#include <bits/stdc++.h>

int solve(std::string s) {
    const int MOD = 998244353;
    int n = s.size();
    std::vector<bool> a(n - 1);
    for (int i = 0; i < n - 1; i++) a[i] = s[i] == s[i + 1];
    int ans = 0;
    for (int l = 0; l < n - 1; l++) {
        int r = std::find(a.begin() + l, a.end(), true) - a.begin();
        ans += n - 1 - r;
        ans %= MOD;
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    int ans = solve(s);
    std::cout << ans << std::endl;
}
