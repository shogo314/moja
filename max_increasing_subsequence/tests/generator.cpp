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

void make_test_nsmall(int idx) {
    std::ofstream out(format("01_testcase_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, 20LL);
    out << N << std::endl;
    std::vector<int> A(N);
    for (int j = 0; j < N; j++) A[j] = rnd.next(MIN_A, MIN_A);
    out << A << std::endl;
    std::vector<int> B(N);
    for (int j = 0; j < N; j++) B[j] = rnd.next(MIN_B, MAX_B);
    out << B << std::endl;
}
void make_test_random(int idx) {
    std::ofstream out(format("02_testcase_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, MAX_N);
    out << N << std::endl;
    std::vector<int> A(N);
    for (int j = 0; j < N; j++) A[j] = rnd.next(MIN_A, MAX_A);
    out << A << std::endl;
    std::vector<int> B(N);
    for (int j = 0; j < N; j++) B[j] = rnd.next(MIN_B, MAX_B);
    out << B << std::endl;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 10; i++) {
        make_test_nsmall(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random(i);
    }
}