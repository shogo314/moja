#include <bits/stdc++.h>

#include <ac-library/modint.hpp>

using mod = atcoder::modint1000000007;

int N;
std::vector<int> A;
std::map<std::array<int, 2>, mod> m;

mod query(int t, int k) {
    if (m.find({t, k}) != m.end()) {
        return m[{t, k}];
    }
    mod ans = 0;
    if (t == k) {
        ans = A[k];
    } else {
        int w = 1 << (std::bit_width((unsigned)(k - t)) - 1);
        ans = query(t, k - w) + query(t + w, k);
    }
    m[{t, k}] = ans;
    return ans;
}

int main() {
    std::cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cout << query(0, i).val() << std::endl;
}