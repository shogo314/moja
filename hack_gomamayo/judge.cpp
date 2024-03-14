#include <bits/stdc++.h>

class Validator {
    int i;
    std::vector<int> data;

    bool is_ascii_letter(int x) {
        return ('a' <= x and x <= 'z') or ('A' <= x and x <= 'Z');
    }
    bool is_ascii_lowercase(int x) {
        return 'a' <= x and x <= 'z';
    }
    bool is_ascii_uppercase(int x) {
        return 'A' <= x and x <= 'Z';
    }
    bool is_digit(int x) {
        return '0' <= x and x <= '9';
    }

   public:
    Validator() {
        while (true) {
            int ch;
            ch = getchar();
            data.push_back(ch);
            if (ch == EOF) break;
        }
        i = 0;
        std::cout << "data =";
        for (int a : data) {
            std::cout << " " << a;
        }
        std::cout << std::endl;
    }
    std::string readString_ascii_letter() {
        std::string ret;
        while (i < data.size() and is_ascii_letter(data[i])) {
            ret.push_back(data[i++]);
        }
        return ret;
    }
    std::string readString_ascii_lowercase() {
        std::string ret;
        while (i < data.size() and is_ascii_lowercase(data[i])) {
            ret.push_back(data[i++]);
        }
        return ret;
    }
    std::string readString_ascii_uppercase() {
        std::string ret;
        while (i < data.size() and is_ascii_uppercase(data[i])) {
            ret.push_back(data[i++]);
        }
        return ret;
    }
    char readSpace() {
        assert(i < data.size());
        assert(data[i] == ' ');
        return data[i++];
    }
    char readChar() {
        assert(i < data.size());
        return data[i++];
    }
    char readChar_ascii_letter() {
        assert(i < data.size());
        assert(is_ascii_letter(data[i]));
        return data[i++];
    }
    void readEoln() {
        assert(i < data.size());
        if (data[i] == '\n') {
            i++;
            return;
        }
        if (i + 1 < data.size() and data[i] == '\r' and data[i + 1] == '\n') {
            i += 2;
            return;
        }
        assert(false);
    }
    void readEof() {
        assert(i < data.size());
        assert(data[i] == EOF);
    }
    void readEof_or_EolnEof() {
        assert(i < data.size());
        if (data[i] == EOF) return;
        assert(i + 1 < data.size());
        if (data[i] == '\n' and data[i + 1] == EOF) return;
        assert(i + 2 < data.size());
        if (data[i] == '\r' and data[i + 1] == '\n' and data[i + 2] == EOF) return;
        assert(false);
    }
    int readInt() {
        assert(i < data.size());
        std::string s;
        while (i < data.size() and is_digit(data[i])) {
            s.push_back(data[i++]);
        }
        assert(s.size() <= 1 or s[0] != '0');
        return std::stoi(s);
    }
    long long readLong() {
        assert(i < data.size());
        std::string s;
        while (i < data.size() and is_digit(data[i])) {
            s.push_back(data[i++]);
        }
        assert(s.size() <= 1 or s[0] != '0');
        return std::stoll(s);
    }
};

class SystemClock {
    std::chrono::system_clock::time_point start_time;

   public:
    SystemClock() {
        start_time = std::chrono::system_clock::now();
    }
    std::chrono::nanoseconds elapsed_time() const {
        std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
        return now_time - start_time;
    }
};

std::string input() {
    Validator validator;
    std::string s = validator.readString_ascii_lowercase();
    validator.readEof_or_EolnEof();
    return s;
}

int correct_answer(std::string s) {
    int n = s.size(), p = 0;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        p = (s[i] == s[i - 1] ? i : p);
        ans += p;
    }
    return ans % 998244353;
}

int solve(std::string s) {
    SystemClock system_clock;
    long long n = s.size();
    std::vector<bool> a(n - 1);
    for (long long i = 0; i < n - 1; i++) a[i] = s[i] == s[i + 1];
    long long ans = 0;
    for (long long l = 0; l < n - 1; l++) {
        long long r = std::find(a.begin() + l, a.end(), true) - a.begin();
        ans += n - 1 - r;
        if (system_clock.elapsed_time() >= std::chrono::milliseconds(2000)) {
            std::exit(0);
        }
    }
    return ans % 998244353;
}

void judge_tle() {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main() {
    SystemClock system_clock;
    std::string s = input();
    int ans = correct_answer(s);
    if (system_clock.elapsed_time() >= std::chrono::milliseconds(500)) {
        judge_tle();
    }
    assert(ans != solve(s));
}
