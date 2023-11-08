# ナニコレ
これは`shogo314`がMojaCoderに投稿する問題を管理するためのGitHubです。

同じ環境で作業したい人と自分のために使い方を書きます。

# 環境
- WSL
- GCCとPython3が使える
- Rimeがインストール済

[Rime](https://github.com/icpc-jag/rime)のインストール
```
pip3 install rime
```

# Rimeの使い方

問題ディレクトリを作る
```
rime add . problem <problem_dir_name>
```

作ったディレクトリに移動
```
cd <problem_dir_name>
```

テストセットディレクトリの作成
```
rime add . testset <testset_dir_name>
```

ジェネレータとバリデータの作成
`<testset_dir_name>`内に`generator.cpp`と`validator.cpp`を作成


解法の作成
```
rime add . solution <solution_dir_name>
```

ジャッジ出力生成・自動テスト
`PROBLEM`を編集してジャッジ出力に使う解法を指定

```
rime test
```
