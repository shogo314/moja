# 問題文
下のコードと同じ出力をするプログラムを書いてください。ただし、下のコードではTLEとなることに注意してください。

入力は、下のコードが正常終了するものである。

```Python
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

```

# 制約
- $1 \leq T \leq 2 \times 10^5$
- $-10^9 \leq A \leq 10^9$
- $-10^9 \leq B \leq 10^9$
- $-10^9 \leq C \leq 10^9$
- $0 \leq q \leq 6$
- $-2 \times 10^9 \leq x \leq 2 \times 10^9$

# 入力
入力は以下の形式で標準入力から与えられる。
```md
$Q$\
query$1$\
query$2$\
$\vdots$\
query$Q$

```

$i$ 番目のクエリ query$i$ では、クエリの種類 $q$ と必要に応じて $x$ が下の形で与えられる。

```md
$q$

```

```md
$q$\
$x$

```

# 出力
答えは $T$ 行である。

# 入力例 1
```
3
100 150 3
0
10 -120 -1
3
3
8 2 3
4
8

```

# 出力例 1
```
2108
7
0

```

# 入力例 2
```
1
-100000000 100000000 1
1

```

# 出力例 2
```
200000001

```
