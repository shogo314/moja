**この問題は特殊な形式です。**

下の問題について、解答コードが与えられますが、これは AC とならない可能性があるコードです。AC とならないテストケースを出力してください。AC とならない場合は AC、与えられたコードで AC になってしまう場合や、入力形式または制約を満たさないケースの場合は WA となります。

# 問題文
[Gomamayo](https://atcoder.jp/contests/oupc2023-day1/tasks/oupc2023_day1_b)
と同じ問題です。

# コード
```cpp
#include <bits/stdc++.h>

int solve(std::string s) {
    const int MOD = 998244353;
    int n = s.size();
    std::vector<bool> a(n - 1);
    for (int i = 0; i < n - 1; i++) a[i] = s[i] == s[i + 1];
    int ans = 0;
    for (int l = 0; l < n - 1; l++) {
        int r = std::find(a.begin() + l, a.end(), true) - a.begin();
        ans += n - 1 - r;
        ans %= MOD;
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    int ans = solve(s);
    std::cout << ans << std::endl;
}

```

この形式のコンテストを一緒に作りませんか？作問に興味のある方は[shogo314](https://twitter.com/shogo3142)に DM を下さい。アイディアを出すだけでも結構です。
