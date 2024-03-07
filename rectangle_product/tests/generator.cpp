#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

void make_test_small(int idx) {
    const long long int LOCAL_MIN_N = 1;
    const long long int LOCAL_MAX_N = 1000;
    const long long int LOCAL_MIN_Q = 1;
    const long long int LOCAL_MAX_Q = 1000;

    std::ofstream out(format("01_small_%02d.in", idx).c_str());
    int N = rnd.next(LOCAL_MIN_N, LOCAL_MAX_N);
    int Q = rnd.next(LOCAL_MIN_Q, LOCAL_MAX_Q);
    out << N << ' ' << Q << std::endl;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int X = rnd.next(MIN_X, MAX_X - 1);
        int Y = rnd.next(MIN_Y, MAX_Y - 1);
        int W = rnd.next(MIN_W, MAX_W);
        out << X << ' ' << Y << ' ' << W << std::endl;
    }
    for (int i = 0; i < Q; i++) {
        int l, r, d, u;
        do {
            l = rnd.next(MIN_X, MAX_X - 1);
            r = rnd.next(MIN_X + 1, MAX_X);
        } while (l >= r);
        do {
            d = rnd.next(MIN_Y, MAX_Y - 1);
            u = rnd.next(MIN_Y + 1, MAX_Y);
        } while (d >= u);
        out << l << ' ' << d << ' ' << r << ' ' << u << std::endl;
    }
}

void make_test_random(int idx) {
    std::ofstream out(format("02_random_%02d.in", idx).c_str());

    int N = rnd.next(MIN_N, MAX_N);
    int Q = rnd.next(MIN_Q, MAX_Q);
    out << N << ' ' << Q << std::endl;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int X = rnd.next(MIN_X, MAX_X - 1);
        int Y = rnd.next(MIN_Y, MAX_Y - 1);
        int W = rnd.next(MIN_W, MAX_W);
        out << X << ' ' << Y << ' ' << W << std::endl;
    }
    for (int i = 0; i < Q; i++) {
        int l, r, d, u;
        do {
            l = rnd.next(MIN_X, MAX_X - 1);
            r = rnd.next(MIN_X + 1, MAX_X);
        } while (l >= r);
        do {
            d = rnd.next(MIN_Y, MAX_Y - 1);
            u = rnd.next(MIN_Y + 1, MAX_Y);
        } while (d >= u);
        out << l << ' ' << d << ' ' << r << ' ' << u << std::endl;
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
