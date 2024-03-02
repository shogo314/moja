#include <cassert>
#include <iostream>
#include <map>
#include <vector>

class CounterSegTree {
    using S = int;
    int n, sz, height;
    std::vector<std::map<S, int>> data;

   public:
    explicit CounterSegTree(const std::vector<S>& v) {
        n = v.size();
        sz = 1;
        height = 0;
        while (sz < n) {
            sz <<= 1;
            height++;
        }
        data.assign(sz * 2, {});
        for (int i = 0; i < n; i++) {
            data[i + sz][v[i]] = 1;
        }
        for (int i = sz - 1; i > 0; i--) {
            data[i] = data[2 * i];
            for (auto [s, c] : data[2 * i + 1]) {
                data[i][s] += c;
            }
        }
    }
    S get(int k) const {
        assert(0 <= k and k < n);
        return data[k + sz].begin()->first;
    }
    void set(int k, const S& x) {
        k += sz;
        S y = data[k].begin()->first;
        while (k > 0) {
            auto itr = data[k].find(y);
            if (itr->second == 1) {
                data[k].erase(itr);
            } else {
                itr->second--;
            }
            data[k][x]++;
            k >>= 1;
        }
    }
    std::pair<S, int> lower_bound(int l, int r, int x) const {
        std::pair<S, int> ret = {{}, 0};
        l += sz;
        r += sz;
        while (l < r) {
            if (l & 1) {
                auto itr = data[l].lower_bound(x);
                if (itr != data[l].end()) {
                    if (ret.second == 0) {
                        ret = *itr;
                    } else if (itr->first == ret.first) {
                        ret.second += itr->second;
                    } else if (itr->first < ret.first) {
                        ret = *itr;
                    }
                }
                ++l;
            }
            if (r & 1) {
                --r;
                auto itr = data[r].lower_bound(x);
                if (itr != data[r].end()) {
                    if (ret.second == 0) {
                        ret = *itr;
                    } else if (itr->first == ret.first) {
                        ret.second += itr->second;
                    } else if (itr->first < ret.first) {
                        ret = *itr;
                    }
                }
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    CounterSegTree cst(A);
    int Q;
    std::cin >> Q;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int p, x;
            std::cin >> p >> x;
            cst.set(p - 1, x);
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto ans = cst.lower_bound(l - 1, r, x);
            std::cout << ans.first << ' ' << ans.second << std::endl;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    solve();
}
