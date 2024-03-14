C 言語の int 型の表現できる範囲は MojaCoder の環境では、-2147483648 ~ 2147483647 です。
計算途中でこの範囲から出る場合、オーバーフローしてしまいます。$A + B + C$ が 2147483647 を超えるように適当な値を選ぶとよいです。制約を満たすように注意しましょう。

※注意  
int のオーバーフローは未定義動作です。オーバーフローするからといっておかしな答えを返すとは限りません。じゃあどういう挙動になるのかというと、わかりません。未定義なので。

正直ジャッジの正しさも保証できないのですが、わかりやすい例としてこの問題を作成しました。