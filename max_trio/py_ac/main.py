#!/usr/bin/pypy3
def solve():
    Y = list(map(int, input().split()))
    ans = 0
    Y.sort()
    if Y[0] < Y[1]:
        t = Y[1] - Y[0]
        for i in range(1, 4):
            Y[i] -= t
        ans += t
    if Y[1] < Y[2]:
        t = min(Y[2] - Y[1], Y[1])
        Y[0] -= t
        Y[1] -= t
        Y[2] -= 2 * t
        Y[3] -= 2 * t
        ans += 2 * t
    if Y[1] > 0:
        t = min(Y[3] - Y[2], Y[1] // 2)
        Y[0] -= 2 * t
        Y[1] -= 2 * t
        Y[2] -= 2 * t
        Y[3] -= 3 * t
        ans += 3 * t
    if Y[0] == 1:
        Y[0] = Y[1] = Y[2] = 0
        ans += 1
    if Y[1] > 0:
        t = Y[0] // 3
        for i in range(4):
            Y[i] -= 3 * t
        ans += 4 * t
        t = Y[0]
        for i in range(3):
            Y[i] -= t
        ans += t
    print(ans)


for _ in range(int(input())):
    solve()
