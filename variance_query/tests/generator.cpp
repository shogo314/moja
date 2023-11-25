#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

template <typename T, typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << CharT(' ');
        os << v[i];
    }
    return os;
}

void make_test_small(int idx) {
    std::ofstream out(format("01_testcase_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, 100LL);
    int Q = rnd.next(MIN_Q, 100LL);
    out << N << ' ' << Q << std::endl;
    std::vector<int> A(N);
    for (int j = 0; j < N; j++) A[j] = rnd.next(MIN_A, 100LL);
    out << A << std::endl;
    for (int j = 0; j < Q; j++) {
        int X = rnd.next(MIN_X, 100LL);
        out << X << std::endl;
    }
}

void make_test_random(int idx) {
    std::ofstream out(format("02_testcase_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, MAX_N);
    int Q = rnd.next(MIN_Q, MAX_Q);
    out << N << ' ' << Q << std::endl;
    std::vector<int> A(N);
    for (int j = 0; j < N; j++) A[j] = rnd.next(MIN_A, MAX_A);
    out << A << std::endl;
    for (int j = 0; j < Q; j++) {
        int X = rnd.next(MIN_X, MAX_X);
        out << X << std::endl;
    }
}

void make_test_big(int idx) {
    const int WIDTH_N = 100;
    const int WIDTH_A = 1;
    const int WIDTH_X = 1;
    static_assert(MIN_N <= MAX_N - WIDTH_N);
    static_assert(MIN_A <= MAX_A - WIDTH_A);
    static_assert(MIN_X <= MAX_X - WIDTH_X);
    std::ofstream out(format("03_testcase_%02d.in", idx).c_str());
    int N = rnd.next(MAX_N - WIDTH_N, MAX_N);
    int Q = rnd.next(MIN_Q, MAX_Q);
    out << N << ' ' << Q << std::endl;
    const int BASE_A = rnd.next(MIN_A, MAX_A - WIDTH_A);
    const int BASE_X = BASE_A;
    std::vector<int> A(N);
    for (int j = 0; j < N; j++) A[j] = rnd.next(BASE_A, BASE_A + WIDTH_A);
    out << A << std::endl;
    for (int j = 0; j < Q; j++) {
        int X = rnd.next(BASE_X, BASE_X + WIDTH_X);
        out << X << std::endl;
    }
}

void make_test_max(int idx) {
    std::ofstream out(format("04_testcase_%02d.in", idx).c_str());
    int N = MAX_N;
    int Q = MAX_Q;
    out << N << ' ' << Q << std::endl;
    const int BASE_A = MAX_A - idx;
    const int BASE_X = MAX_X;
    std::vector<int> A(N, BASE_A);
    out << A << std::endl;
    for (int j = 0; j < Q; j++) {
        int X = MAX_X - j;
        out << X << std::endl;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 10; i++) {
        make_test_small(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_big(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_max(i);
    }
}