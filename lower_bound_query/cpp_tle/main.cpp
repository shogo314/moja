#include <cassert>
#include <iostream>
#include <map>
#include <vector>

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    int Q;
    std::cin >> Q;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int p, x;
            std::cin >> p >> x;
            A[p - 1] = x;
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::pair<int, int> ans = {0, 0};
            for (int i = l - 1; i < r; i++) {
                if (A[i] < x) continue;
                if (ans.second == 0) {
                    ans = {A[i], 1};
                } else if (A[i] == ans.first) {
                    ans.second++;
                } else if (A[i] < ans.first) {
                    ans = {A[i], 1};
                }
            }
            std::cout << ans.first << ' ' << ans.second << std::endl;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    solve();
}
