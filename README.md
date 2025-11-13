## AtCoder用C++開発環境(vscode + docker)
### 環境
```
c++
```

### ライブラリ
* C++
```
ACL
```

### 実行方法
1. `ctrl + alt + n`
2. デバッグ実行

# コマンド系まとめ
### ログイン
```bash
# atcoder cliログイン
acc login
# online-judge-toolsログイン
oj login https://beta.atcoder.jp/
```

### 使えるコマンドまとめ
- コンテスト用ディレクトリ作成
```bash
acc new contestID
```

- テストケース追加
```bash
acc add --force
```

- テスト実行
```bash
# python
oj t -c " python ./a.py" -d ./tests/
# c++
oj t -d ./tests/
```

### 提出
```bash
acc submit <ファイル名>
# python、pypyにはファイル内の先頭に以下をつける必要あり
#!/usr/bin/env python3
#!/usr/bin/env pypy
```

### 参考
- ****[atcoder初心者こそ環境構築しよう！(atcoder-cli,online-judge-toolsのインストール、使い方](https://qiita.com/Adaachill/items/3d4ddad56c5c2cc372cd)****
- ****[DockerでAtCoderができる環境を作る【Python・C++】](https://qiita.com/hinamimi/items/b3dd159f956628cebdbb)****
