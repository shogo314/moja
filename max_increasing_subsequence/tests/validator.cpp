#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    std::vector<int> A(N);
    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        A[i] = inf.readInt(MIN_A, MAX_A);
        if (i != N - 1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    for (int i = 0; i < N; i++) {
        B[i] = inf.readInt(MIN_B, MAX_B);
        if (i != N - 1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}