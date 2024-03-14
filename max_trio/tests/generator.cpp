#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

void make_test_small(int idx) {
    const long long int LOCAL_MIN_T = 1;
    const long long int LOCAL_MAX_T = 100;
    const long long int LOCAL_MIN_A = 0;
    const long long int LOCAL_MAX_A = 100;
    std::ofstream out(format("01_small_%02d.in", idx).c_str());
    int T = rnd.next(LOCAL_MIN_T, LOCAL_MAX_T);
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int a, b, c, d;
        a = rnd.next(LOCAL_MIN_A, LOCAL_MAX_A);
        b = rnd.next(LOCAL_MIN_A, LOCAL_MAX_A);
        c = rnd.next(LOCAL_MIN_A, LOCAL_MAX_A);
        d = rnd.next(LOCAL_MIN_A, LOCAL_MAX_A);
        out << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
    }
}

void make_test_random(int idx) {
    std::ofstream out(format("02_random_%02d.in", idx).c_str());
    int T = rnd.next(MIN_T, MAX_T);
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int a, b, c, d;
        a = rnd.next(MIN_A, MAX_A);
        b = rnd.next(MIN_A, MAX_A);
        c = rnd.next(MIN_A, MAX_A);
        d = rnd.next(MIN_A, MAX_A);
        out << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 5; i++) {
        make_test_small(i);
    }
    for (int i = 0; i < 5; i++) {
        make_test_random(i);
    }
}
