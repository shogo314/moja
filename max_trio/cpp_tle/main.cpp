#include <bits/stdc++.h>

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int ans = 0;
    std::array<int, 4> v = {a, b, c, d};
    std::sort(v.begin(), v.end());
    while (v[1] > 0) {
        ans++;
        v[1]--;
        v[2]--;
        v[3]--;
        std::sort(v.begin(), v.end());
    }
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
