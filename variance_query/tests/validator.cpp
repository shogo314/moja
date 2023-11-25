#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    int Q = inf.readInt(MIN_Q, MAX_Q);
    inf.readEoln();
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = inf.readInt(MIN_A, MAX_A);
        if (i != N - 1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    for (int i = 0; i < Q; i++) {
        int X = inf.readInt(MIN_X, MAX_X);
        inf.readEoln();
    }
    inf.readEof();
}