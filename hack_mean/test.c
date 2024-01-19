#include <stdio.h>

int solve(int A, int B, int C) {
    return (A + B + C) / 3;
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int ans = solve(A, B, C);
    printf("%d\n", ans);
}
