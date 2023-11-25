#include <bits/stdc++.h>
int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<double> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    double sum_A = 0, sum_A2 = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        sum_A += A[i];
        sum_A2 += A[i] * A[i];
    }
    double n = N + 1;
    std::cout << std::fixed << std::setprecision(15);
    for (int i = 0; i < Q; i++) {
        double X;
        std::cin >> X;
        double ans = (sum_A2 + X * X) / n - ((sum_A + X) / n) * ((sum_A + X) / n);
        std::cout << ans << std::endl;
    }
}