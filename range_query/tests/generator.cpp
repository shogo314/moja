#include <bits/stdc++.h>

#include "constraints.hpp"
#include "testlib.h"

struct Range {
   public:
    using value_type = long long;
    const value_type start;
    const value_type step;
    const value_type stop;

   private:
    value_type norm_stop;

    constexpr static value_type normalize(value_type __start, value_type __stop, value_type __step) {
        assert(__step != 0);
        if (__step > 0) {
            if (__start >= __stop) {
                return __start;
            } else {
                return __start + (__stop - __start + __step - 1) / __step * __step;
            }
        } else {
            if (__start <= __stop) {
                return __start;
            } else {
                return __start - (__start - __stop - __step - 1) / (-__step) * (-__step);
            }
        }
    }

   public:
    constexpr Range(value_type __start, value_type __stop, value_type __step)
        : start(__start), stop(__stop), step(__step), norm_stop(normalize(__start, __stop, __step)) {
    }
    constexpr Range(value_type __start, value_type __stop)
        : start(__start), stop(__stop), step(1), norm_stop(normalize(__start, __stop, 1)) {}
    constexpr Range(value_type __stop)
        : start(0), stop(__stop), step(1), norm_stop(normalize(0, __stop, 1)) {}

    struct const_iterator {
       private:
        const Range& range;
        value_type value;

        constexpr bool same_range(const const_iterator& o) const noexcept {
            return range.start == o.range.start and range.stop == o.range.stop and range.step == o.range.step;
        }

       public:
        constexpr const_iterator(const Range& __range, value_type __value) noexcept
            : range(__range), value(__value) {}
        constexpr const_iterator(const const_iterator& o) noexcept
            : range(o.range), value(o.value) {}
        constexpr const value_type& base() const noexcept {
            return value;
        }
        constexpr const_iterator& operator=(const const_iterator& o) {
            assert(same_range(o));
            value = o.value;
        };
        constexpr const_iterator& operator++() noexcept {
            value += range.step;
            return *this;
        }
        constexpr const_iterator operator++(int) noexcept {
            const_iterator ret(*this);
            value += range.step;
            return ret;
        }
        constexpr const_iterator& operator+=(std::ptrdiff_t __n) noexcept {
            value += __n * range.step;
            return *this;
        }
        constexpr const_iterator operator+(std::ptrdiff_t __n) const noexcept {
            const_iterator ret(*this);
            ret += __n;
            return ret;
        }
        constexpr const_iterator& operator--() noexcept {
            value -= range.step;
            return *this;
        }
        constexpr const_iterator operator--(int) noexcept {
            const_iterator ret(*this);
            value -= range.step;
            return ret;
        }
        constexpr const_iterator& operator-=(std::ptrdiff_t __n) noexcept {
            value -= __n * range.step;
            return *this;
        }
        constexpr const_iterator operator-(std::ptrdiff_t __n) const noexcept {
            const_iterator ret(*this);
            ret -= __n;
            return ret;
        }
        constexpr value_type operator*() const noexcept {
            return value;
        }
        constexpr friend bool operator!=(const const_iterator& a, const const_iterator& b) noexcept {
            return !a.same_range(b) or a.value != b.value;
        }
        constexpr friend bool operator==(const const_iterator& a, const const_iterator& b) noexcept {
            return !(a != b);
        }
        constexpr friend std::ptrdiff_t operator-(const const_iterator& a, const const_iterator& b) {
            assert(a.same_range(b));
            if (a.range.step > 0) {
                return (a.value - b.value) / a.range.step;
            } else {
                return (b.value - a.value) / (-a.range.step);
            }
        }
    };

    constexpr const_iterator begin() const noexcept {
        return {*this, start};
    }
    constexpr const_iterator end() const noexcept {
        return {*this, norm_stop};
    }
    constexpr std::ptrdiff_t count(value_type x) const noexcept {
        if (step > 0) {
            if (start <= x and x < stop) {
                if ((x - start) % step == 0) {
                    return 1;
                }
            }
        } else {
            if (stop < x and x <= start) {
                if ((start - x) % (-step) == 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    constexpr bool contains(value_type x) const noexcept {
        return count(x) != 0;
    }
    constexpr size_t index(value_type x) const {
        assert(contains(x));
        if (step > 0) {
            return (x - start) / step;
        } else {
            return (start - x) / (-step);
        }
    }
    constexpr const_iterator find(value_type x) const noexcept {
        if (contains(x)) {
            return {*this, x};
        } else {
            return {*this, norm_stop};
        }
    }
    constexpr const_iterator lower_bound(value_type x) const {
        assert(step > 0);
        if (norm_stop <= x) {
            return end();
        } else if (x < start) {
            return begin();
        } else {
            return {*this, start + (x - start + step - 1) / step * step};
        }
    }
    constexpr const_iterator upper_bound(value_type x) const {
        assert(step > 0);
        if (norm_stop <= x) {
            return end();
        } else if (x < start) {
            return begin();
        } else {
            return {*this, start + (x - start + step) / step * step};
        }
    }
    constexpr size_t size() const noexcept {
        if (step > 0) {
            return (norm_stop - start) / step;
        } else {
            return (start - norm_stop) / (-step);
        }
    }
    constexpr value_type at(size_t i) const {
        assert(0 <= i and i < size());
        return start + i * step;
    }
    constexpr value_type operator[](size_t i) const {
        return at(i);
    }
    constexpr bool empty() const noexcept {
        return start == norm_stop;
    }
    constexpr value_type __sum__() const noexcept {
        value_type ret = 0;
        value_type l = size();
        return l * (l - 1) / 2 * step + l * start;
    }
    constexpr Range __reversed__() const noexcept {
        return {norm_stop - step, start - step, -step};
    }
    std::string __repr__() const {
        using std::string, std::to_string;
        return string("Range(") + to_string(start) + ", " + to_string(stop) + ", " + to_string(step) + string(")");
    }
    std::vector<value_type> to_vector() const {
        std::vector<value_type> ret;
        ret.reserve(size());
        if (step > 0) {
            for (value_type x = start; x < stop; x += step) {
                ret.push_back(x);
            }
        } else {
            for (value_type x = start; x > stop; x += step) {
                ret.push_back(x);
            }
        }
        return ret;
    }
    constexpr friend bool operator==(const Range& a, const Range& b) noexcept {
        if (a.empty() and b.empty()) return true;
        if (a.size() != b.size()) return false;
        if (a.start != b.start) return false;
        if (a.size() == 1) return true;
        if (a.step != b.step) return false;
        return true;
    }
    constexpr friend bool operator!=(const Range& a, const Range& b) noexcept {
        return !(a == b);
    }
};

template <>
struct std::iterator_traits<Range::const_iterator> {
    using difference_type = std::ptrdiff_t;
    using value_type = Range::const_iterator;
    using pointer = const Range::value_type*;
    using reference = const Range::value_type&;
    using iterator_category = std::random_access_iterator_tag;
};

void make_test_small(int idx) {
    const long long int LOCAL_MIN_T = 1;
    const long long int LOCAL_MAX_T = 10000;
    const long long int LOCAL_MIN_A = -10000;
    const long long int LOCAL_MAX_A = 10000;
    const long long int LOCAL_MIN_B = -10000;
    const long long int LOCAL_MAX_B = 10000;
    const long long int LOCAL_MIN_C = -10000;
    const long long int LOCAL_MAX_C = 10000;
    const long long int LOCAL_MIN_X = -10000;
    const long long int LOCAL_MAX_X = 10000;

    std::ofstream out(format("01_small_%02d.in", idx).c_str());
    int T = rnd.next(LOCAL_MIN_T, LOCAL_MAX_T);
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int A = rnd.next(LOCAL_MIN_A, LOCAL_MAX_A);
        int B = rnd.next(LOCAL_MIN_B, LOCAL_MAX_B);
        int C;
        do {
            C = rnd.next(LOCAL_MIN_C, LOCAL_MAX_C);
        } while (C == 0);
        Range R(A, B, C);
        int q, x;
        do {
            q = rnd.next(0, 6);
            if (R.empty() and (q == 2 or q == 3)) {
                continue;
            }
            if (C < 0 and (q == 5 or q == 6)) {
                continue;
            }
            break;
        } while (true);
        if (q >= 2) {
            if (q == 2) {
                x = rnd.next(R.size());
            } else if (q == 3) {
                x = R.at(rnd.next(R.size()));
            } else if (q == 4) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(LOCAL_MIN_X, LOCAL_MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 5) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(LOCAL_MIN_X, LOCAL_MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 6) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(LOCAL_MIN_X, LOCAL_MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            }
        }

        out << A << ' ' << B << ' ' << C << std::endl;
        if (q <= 1) {
            out << q << std::endl;
        } else {
            out << q << std::endl;
            out << x << std::endl;
        }
    }
}

void make_test_random0(int idx) {
    std::ofstream out(format("02_random_%02d.in", idx).c_str());
    int T = rnd.next(MIN_T, MAX_T);
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int A = rnd.next(MIN_A, MAX_A);
        int B = rnd.next(MIN_B, MAX_B);
        int C;
        do {
            C = rnd.next(MIN_C, MAX_C);
        } while (C == 0);
        Range R(A, B, C);
        int q, x;
        do {
            q = rnd.next(0, 6);
            if (R.empty() and (q == 2 or q == 3)) {
                continue;
            }
            if (C < 0 and (q == 5 or q == 6)) {
                continue;
            }
            break;
        } while (true);
        if (q >= 2) {
            if (q == 2) {
                x = rnd.next(R.size());
            } else if (q == 3) {
                x = R.at(rnd.next(R.size()));
            } else if (q == 4) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 5) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 6) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            }
        }

        out << A << ' ' << B << ' ' << C << std::endl;
        if (q <= 1) {
            out << q << std::endl;
        } else {
            out << q << std::endl;
            out << x << std::endl;
        }
    }
}

void make_test_random1(int idx) {
    const long long int LOCAL_MIN_C = -10;
    const long long int LOCAL_MAX_C = 10;
    std::ofstream out(format("03_random_%02d.in", idx).c_str());
    int T = MAX_T;
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int A = rnd.next(MIN_A, MAX_A / 2);
        int B = rnd.next(MIN_B / 2, MAX_B);
        int C;
        do {
            C = rnd.next(LOCAL_MIN_C, LOCAL_MAX_C);
        } while (C == 0);
        Range R(A, B, C);
        int q, x;
        do {
            q = rnd.next(0, 6);
            if (R.empty() and (q == 2 or q == 3)) {
                continue;
            }
            if (q == 0) {
                continue;
            }
            if (C < 0 and (q == 5 or q == 6)) {
                continue;
            }
            break;
        } while (true);
        if (q >= 2) {
            if (q == 2) {
                x = rnd.next(R.size());
            } else if (q == 3) {
                x = R.at(rnd.next(R.size()));
            } else if (q == 4) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 5) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 6) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            }
        }

        out << A << ' ' << B << ' ' << C << std::endl;
        if (q <= 1) {
            out << q << std::endl;
        } else {
            out << q << std::endl;
            out << x << std::endl;
        }
    }
}

void make_test_random2(int idx) {
    const long long int LOCAL_MIN_C = -10;
    const long long int LOCAL_MAX_C = 10;
    std::ofstream out(format("04_random_%02d.in", idx).c_str());
    int T = MAX_T;
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int A = rnd.next(MIN_A, MAX_A / 2);
        int B = rnd.next(MIN_B / 2, MAX_B);
        int C;
        do {
            C = rnd.next(LOCAL_MIN_C, LOCAL_MAX_C);
        } while (C == 0);
        Range R(A, B, C);
        int q, x;
        do {
            q = rnd.next(0, 6);
            if (R.empty() and (q == 2 or q == 3)) {
                continue;
            }
            if (C < 0 and (q == 5 or q == 6)) {
                continue;
            }
            break;
        } while (true);
        if (q >= 2) {
            if (q == 2) {
                x = rnd.next(R.size());
            } else if (q == 3) {
                x = R.at(rnd.next(R.size()));
            } else if (q == 4) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 5) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 6) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            }
        }

        out << A << ' ' << B << ' ' << C << std::endl;
        if (q <= 1) {
            out << q << std::endl;
        } else {
            out << q << std::endl;
            out << x << std::endl;
        }
    }
}

void make_test_max(int idx) {
    std::ofstream out(format("05_max_%02d.in", idx).c_str());
    int T = MAX_T;
    out << T << std::endl;
    for (int i = 0; i < T; i++) {
        int A = MIN_A;
        int B = MAX_B;
        int C = 1;
        Range R(A, B, C);
        int q, x;
        do {
            q = rnd.next(0, 6);
            if (R.empty() and (q == 2 or q == 3)) {
                continue;
            }
            if (C < 0 and (q == 5 or q == 6)) {
                continue;
            }
            break;
        } while (true);
        if (q >= 2) {
            if (q == 2) {
                x = rnd.next(R.size());
            } else if (q == 3) {
                x = R.at(rnd.next(R.size()));
            } else if (q == 4) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 5) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            } else if (q == 6) {
                if (rnd.next(0, 1) or R.empty()) {
                    x = rnd.next(MIN_X, MAX_X);
                } else {
                    x = R.at(rnd.next(R.size()));
                }
            }
        }

        out << A << ' ' << B << ' ' << C << std::endl;
        if (q <= 1) {
            out << q << std::endl;
        } else {
            out << q << std::endl;
            out << x << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 10; i++) {
        make_test_small(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random0(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random1(i);
    }
    for (int i = 0; i < 10; i++) {
        make_test_random2(i);
    }
    make_test_max(0);
}
