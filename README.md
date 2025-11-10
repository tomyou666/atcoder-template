## AtCoder用C++開発環境(vscode + docker)
### 環境
```
c++
python
pypy
```

### ライブラリ
* C++
```
ACL
```

* python
```
numpy==1.18.2
scipy==1.4.1
scikit-learn==0.22.2.post1
numba==0.48.0
networkx==2.4
black
isort
flake8
mypy
ACL
```

### 実行方法
1. `ctrl + n`
  * pypyで実行する場合は拡張子を`.py.py`にする
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
