#include <bits/stdc++.h>

std::tuple<int, int, int> parse(std::string s) {
    assert(!s.empty());
    if (s.back() == '\r') {
        s.pop_back();
    }
    assert(!s.empty());
    std::vector<std::string> split = {""};
    for (char c : s) {
        if (c == ' ') {
            split.push_back("");
            assert(split.back().size() == 0);
        } else if ('0' <= c && c <= '9') {
            if (split.back().empty() && c == '0') {
                assert(false);
            }
            split.back().push_back(c);
        } else {
            assert(false);
        }
    }
    assert(split.size() == 3);
    std::vector<long long> tmp;
    for (size_t i = 0; i < 3; i++) {
        assert(split[i].size() <= 10);
        tmp.push_back(std::stoll(split[i]));
        assert(1 <= tmp.back() && tmp.back() <= 1000000000);
        assert(tmp.back() % 3 == 0);
    }
    return {tmp[0], tmp[1], tmp[2]};
}

std::tuple<int, int, int> input() {
    std::string s;
    std::getline(std::cin, s);
    const auto [A, B, C] = parse(s);
    assert(!std::getline(std::cin, s));
    return {A, B, C};
}

int correct_answer(int A, int B, int C) {
    return A / 3 + B / 3 + C / 3;
}

int solve(int A, int B, int C) {
    return (A + B + C) / 3;
}

int main() {
    const auto [A, B, C] = input();
    assert(correct_answer(A, B, C) != solve(A, B, C));
}
