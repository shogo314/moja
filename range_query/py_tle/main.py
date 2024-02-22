#!/usr/bin/pypy3
import bisect

T = int(input())
for _ in range(T):
    A, B, C = map(int, input().split())
    R = range(A, B, C)
    q = int(input())
    if q == 0:
        print(sum(R))
    elif q == 1:
        print(len(R))
    elif q == 2:
        x = int(input())
        assert 0 <= x < len(R)
        print(R[x])
    elif q == 3:
        x = int(input())
        assert x in R
        print(R.index(x))
    elif q == 4:
        x = int(input())
        print(R.count(x))
    elif q == 5:
        assert C > 0
        x = int(input())
        print(bisect.bisect_left(R, x))
    elif q == 6:
        assert C > 0
        x = int(input())
        print(bisect.bisect_right(R, x))
    else:
        exit(1)
