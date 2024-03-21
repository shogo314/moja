#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    int ans = 0;
    for (int a = 0; a <= N; a++)
        for (int b = 0; b <= N; b++)
            for (int c = 0; c <= N; c++)
                if (a * a + b * b == c * c) ans++;
    std::cout << ans << std::endl;
}
