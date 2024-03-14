#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    int Q = inf.readInt(MIN_Q, MAX_Q);
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        int X = inf.readInt(MIN_X, MAX_X - 1);
        inf.readSpace();
        int Y = inf.readInt(MIN_Y, MAX_Y - 1);
        inf.readSpace();
        int W = inf.readInt(MIN_W, MAX_W);
        inf.readEoln();
    }
    for (int i = 0; i < Q; i++) {
        int l = inf.readInt(MIN_X, MAX_X - 1);
        inf.readSpace();
        int d = inf.readInt(MIN_Y, MAX_Y - 1);
        inf.readSpace();
        int r = inf.readInt(l + 1, MAX_X);
        inf.readSpace();
        int u = inf.readInt(d + 1, MAX_Y);
        inf.readEoln();
    }
    inf.readEof();
}
