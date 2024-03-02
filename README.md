# ナニコレ
これは`shogo314`がMojaCoderに投稿する問題を管理するためのGitHubです。

同じ環境で作業したい人と自分のために使い方を書きます。

# 環境
- WSL
- GCCとPython3が使える
- Rimeがインストール済
- moja_toolsがインストール済

[Rime](https://github.com/icpc-jag/rime)のインストール
```
pip3 install rime
```

[moja_tools](https://github.com/shogo314/moja_tools)のインストール
```
pip3 install git+https://github.com/shogo314/moja_tools.git
```

# Rimeの使い方

### プロジェクトディレクトリを作る
`PROJECT`ファイルを作る。内容をどうすればいいのかはよくわかってません。コピペしてください。
`common/testlib.h`を用意する。便利なので。

### 問題ディレクトリを作る
```
rime add . problem <problem_dir_name>
```

### 作ったディレクトリに移動
```
cd <problem_dir_name>
```

### テストセットディレクトリの作成
```
rime add . testset <testset_dir_name>
```
`TESTSET`の中をいい感じに編集

### ジェネレータとバリデータの作成
`<testset_dir_name>`内に`generator.cpp`と`validator.cpp`を作成

### 解法の作成
```
rime add . solution <solution_dir_name>
```

`SOLUTION`の中を編集する。どうするかは実際のコードを参考にしてください。
想定誤答を作るときは`challenge_cases`を入れることに注意してください。

`PROBLEM`の中の`reference_solution`を設定する。
これをもとに答えが生成される。

### ジャッジ出力生成・自動テスト
`PROBLEM`を編集してジャッジ出力に使う解法を指定

```
rime test
```

# moja_toolsを使う
### 問題タイトルを決める
`PROBLEM`の`title`が問題タイトルとなる。
`problem.json`がある場合そちらが優先される。

### 問題と解説を書く
問題ディレクトリ内に`README.md`を作り、問題文を作成する。

`EDITORIAL.md`も書く（なくてもよい）。

### zipを作る
```
rime test
```
を実行したあとの状態を想定している。

```
mjtools rime_to_zip .
```

`moja-out`の中に`README.md`、`EDITORIAL.md`、`problem.json`が作成される。
`rime-out`を参照して`moja-out`の中にテストケースが作成される。

`moja-out`をもとに問題ディレクトリと同名のzipが作成される。
