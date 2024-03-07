#include <array>
#include <iostream>
#include <vector>
constexpr int MOD = 1000000007;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::array<int, 3>> XYW(N);
    for (auto& [X, Y, W] : XYW) {
        std::cin >> X >> Y >> W;
    }
    while (Q--) {
        int L, D, R, U;
        std::cin >> L >> D >> R >> U;
        long ans = 1;
        for (auto [X, Y, W] : XYW) {
            if (L <= X and X < R and D <= Y and Y < U) {
                ans *= W;
                ans %= MOD;
            }
        }
        std::cout << ans << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    solve();
}
