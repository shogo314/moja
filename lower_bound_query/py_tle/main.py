#!/usr/bin/pypy3
import bisect

N = int(input())
A = list(map(int, input().split()))
Q = int(input())
for _ in range(Q):
    q = tuple(map(int, input().split()))
    if q[0] == 1:
        _, p, x = q
        A[p - 1] = x
    else:
        _, l, r, x = q
        B = sorted(A[l - 1 : r])
        i = bisect.bisect_left(B, x)
        if i == len(B):
            print(0, 0)
            continue
        j = bisect.bisect_right(B, B[i])
        print(B[i], j - i)
