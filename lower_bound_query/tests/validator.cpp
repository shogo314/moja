#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        int A = inf.readInt(MIN_A, MAX_A);
        if (i != N - 1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    int Q = inf.readInt(MIN_Q, MAX_Q);
    inf.readEoln();
    for (int i = 0; i < Q; i++) {
        int t = inf.readInt(1, 2);
        inf.readSpace();
        if (t == 1) {
            int p = inf.readInt(1, N);
            inf.readSpace();
            int x = inf.readInt(MIN_X, MAX_X);
        } else {
            int l = inf.readInt(1, N);
            inf.readSpace();
            int r = inf.readInt(1, N);
            assert(l <= r);
            inf.readSpace();
            int x = inf.readInt(MIN_X, MAX_X);
        }
        inf.readEoln();
    }
    inf.readEof();
}
