#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

void make_test_small(int idx) {
    const long long int LOCAL_MAX_N = 100;
    std::ofstream out(format("01_small_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, LOCAL_MAX_N);
    out << N << std::endl;
}
void make_test_random(int idx) {
    std::ofstream out(format("02_random_%02d.in", idx).c_str());
    int N = rnd.next(MIN_N, MAX_N);
    out << N << std::endl;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 10; i++) {
        make_test_small(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random(i);
    }
}
