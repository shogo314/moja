#include <bits/stdc++.h>

#include <ac-library/modint.hpp>

using mod = atcoder::modint1000000007;

int N;
std::vector<int> A;

int X(int l, int r) {
    if (l == 0 or r == 0) return 1;
    return X(l-1,r)^X(l,r-1);
}

int main() {
    std::cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int k = 0; k < N; k++) {
        mod t = 0;
        for (int i = 0; i < k + 1; i++) t += A[i] * X(i, k - i);
        std::cout << t.val() << std::endl;
    }
}