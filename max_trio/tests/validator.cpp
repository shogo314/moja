#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int A, T = inf.readInt(MIN_T, MAX_T);
    inf.readEoln();
    for (int i = 0; i < T; i++) {
        A = inf.readInt(MIN_A, MAX_A);
        inf.readSpace();
        A = inf.readInt(MIN_A, MAX_A);
        inf.readSpace();
        A = inf.readInt(MIN_A, MAX_A);
        inf.readSpace();
        A = inf.readInt(MIN_A, MAX_A);
        inf.readEoln();
    }
    inf.readEof();
}
