#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::array<int, 3>> v;
    for (int i = 1; i < N; i++) {
        if (2 * i * i >= N) break;
        for (int j = i + 1; j < N; j++) {
            if (i * i + j * j > N) break;
            if (std::gcd(i, j) > 1) continue;
            if ((i + j) % 2 == 0) continue;
            std::array<int, 3> tmp = {j * j - i * i, 2 * i * j, i * i + j * j};
            std::sort(tmp.begin(), tmp.end());
            v.push_back(tmp);
        }
    }
    int ans = 2 * N + 1;
    for (const auto& t : v) {
        ans += N / t[2] * 2;
    }
    std::cout << ans << std::endl;
}
