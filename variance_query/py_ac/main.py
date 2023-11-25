#!/usr/bin/python3
from decimal import Decimal, getcontext, ROUND_HALF_UP

getcontext().prec = 500
N, Q = map(int, input().split())
A = list(map(int, input().split()))
sum_A = Decimal(sum(A))
sum_A2 = Decimal(sum(a**2 for a in A))
n = Decimal(N + 1)
for _ in range(Q):
    X = Decimal(int(input()))
    ans = (sum_A2 + X**2) / n - ((sum_A + X) / n) ** 2
    print(f"{ans:.30f}")
