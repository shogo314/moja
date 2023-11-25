#include <bits/stdc++.h>
int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<double> A(N);
    long long tmp = 0;
    for (int i = 0; i < N; i++) {
        long long a;
        std::cin >> a;
        tmp += a;
        A[i] = a;
    }
    tmp /= N;
    double sum_A = 0, sum_A2 = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        A[i] -= tmp;
        sum_A += A[i];
        sum_A2 += A[i] * A[i];
    }
    double n = N + 1;
    std::cout << std::fixed << std::setprecision(15);
    for (int i = 0; i < Q; i++) {
        long long x;
        std::cin >> x;
        double X = x - tmp;
        double ans = (sum_A2 + X * X) / n - ((sum_A + X) / n) * ((sum_A + X) / n);
        std::cout << ans << std::endl;
    }
}