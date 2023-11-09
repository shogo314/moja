#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::vector<int> B(N);
    for (int i = 0; i < N; i++) std::cin >> B[i];
    int N_ = 1 << N;
    long long ans = 0;
    for (int i = 0; i < N_; i++) {
        bool flag = true;
        {
            int t = 0;
            for (int j = 0; j < N; j++) {
                if ((i >> j) & 1) {
                    if (A[j] <= t) {
                        flag = false;
                        break;
                    }
                    t = A[j];
                }
            }
        }
        if (!flag) continue;
        {
            long long t = 0;
            for (int j = 0; j < N; j++) {
                if ((i >> j) & 1) {
                    t += B[j];
                }
            }
            ans = std::max(ans, t);
        }
    }
    std::cout << ans << std::endl;
}