# AtCoder用C++開発環境 (VS Code + Docker)

このリポジトリは、AtCoder競技プログラミング用のC++開発環境を提供します。VS CodeとDockerを使用して、統一された開発環境を構築できます。

## 概要

この開発環境は以下の特徴を持ちます：

- **Dockerコンテナベース**: 環境の統一性を保証
- **VS Code Dev Containers**: シームレスな開発体験
- **C++23対応**: 最新のC++標準に対応
- **AtCoder Library統合**: ACLを簡単に使用可能
- **デバッグ機能**: GDBによるデバッグサポート
- **コードフォーマット**: clang-formatによる自動フォーマット
- **LSPサポート**: clangdによる高度なコード補完とエラー検出

## 環境要件

### 必須ソフトウェア

- **Docker Desktop** (またはDocker Engine)
  - Windows/Mac: [Docker Desktop](https://www.docker.com/products/docker-desktop/)
  - Linux: Docker Engine
- **Visual Studio Code**
  - [VS Code公式サイト](https://code.visualstudio.com/)
- **Dev Containers拡張機能**
  - VS Code拡張機能マーケットプレイスからインストール

## セットアップ

### 1. リポジトリのクローン

```bash
git clone git@github.com:tomyou666/atcoder-template.git
cd AtCoder
```

### 2. VS Codeでプロジェクトを開く

```bash
code .
```

### 3. Dev Containerで開く

1. VS Codeのコマンドパレットを開く（`Ctrl+Shift+P` / `Cmd+Shift+P`）
2. 「Dev Containers: Reopen in Container」を選択
3. 初回起動時は、Dockerイメージのビルドに数分かかります

### 4. 動作確認
**インストール確認：**

コンテナが起動したら、ターミナルで以下を実行して確認：

```bash
g++ --version
clangd --version
```

**実行確認：**

1. `test.cpp`というファイルを作成して、以下のサンプルコードを書きます：

```cpp
#include <iostream>
using namespace std;

int main() {
    cout >> "Hello World" >> endl;
    return 0;
}
```

2. `Ctrl+Alt+N`（Mac: `Cmd+Alt+N`）で実行します

3. ターミナルに「Hello World」と表示されれば成功です！

## プロジェクト構成

```
AtCoder/
├── .devcontainer/         # Dev Container設定
│   ├── Dockerfile       # Dockerイメージ定義
│   └── devcontainer.json # コンテナ設定ファイル
├── .vscode/               # VS Code設定
│   ├── settings.json     # エディタ設定
│   ├── launch.json       # デバッグ設定
│   └── tasks.json        # タスク設定
├── .clang-format          # コードフォーマット設定
├── .clangd                # clangd設定
├── template.cpp           # C++テンプレートファイル
├── test.cpp               # テスト用ファイル
├── module/                # 共通モジュール
│   └── algorithm.cpp     # アルゴリズム実装例
└── README.md              # このファイル
```

## 開発環境の詳細

### インストール済みツール

**コンパイラ・開発ツール**
- `g++-13`: GNU C++コンパイラ（C++23対応）**※ 実行用**
- `clang`: LLVM C++コンパイラ **※ リント・補完する用**
- `clangd`: Language Server Protocol実装
- `gdb`: デバッガー

**ユーティリティ**
- `zsh`: Z Shell（デフォルトシェル）
- `time`: 実行時間測定
- `tree`: ディレクトリ構造表示
- `git`: バージョン管理
- `curl`: HTTPクライアント

**AtCoder関連ツール**
- **AtCoder Library (ACL)**: `/lib/ac-library`にインストール済み
- **atcoder-cli (acc)**: コンテスト管理ツール。コンテスト用ディレクトリの作成や提出を自動化できます。詳細は[公式インストールガイド](http://tatamo.81.la/blog/2018/12/07/atcoder-cli-installation-guide/)を参照してください。
- **atcs**: AtCoder用のURLを指定して問題文を取得するシンプルなスクレイピングツール。復習目的での問題文をAIに読み込ませる際に便利なツールです。詳細は [AtCoder シンプルなスクレイピングツール「atcs」の紹介](https://qiita.com/tomyou666/items/6acf1f048b81a24da58b) を参照してください。

**その他**
- `nodejs` / `npm`: JavaScript実行環境（atcoder-cli実行用）

### シンボリックリンク

- `g++` → `g++-13`: デフォルトでg++-13を使用

## 使用方法

### 新しい問題の作成

1. 問題用のディレクトリを作成
```bash
mkdir abc123-a
cd abc123-a
```

2. テンプレートをコピー
```bash
cp ../template.cpp main.cpp
```

3. VS Codeで開いて編集

### コードの実行

#### 方法1: Code Runner拡張機能を使用

1. ファイルを開く
2. `Ctrl+Alt+N`（Mac: `Cmd+Alt+N`）で実行
3. または、右上の▶ボタンをクリック

**実行コマンド**: `g++ -O2 -std=c++23 "$fileName" && ./a.out && rm ./a.out`

#### 方法2: ターミナルから実行

```bash
g++ -O2 -std=c++23 main.cpp -o main
./main
```

#### 方法3: デバッグモードで実行（ブレークポイントを利用したい場合）

F5キーを押すか、デバッグパネルから「C++:Debug」を選択

ブレークポイントで止まってくれます。

### コードのフォーマット

- **フォーマッター**: clangd（clang-format使用）

## デバッグ機能（ブレークポイントを利用したい場合）

通常の実行（Ctrl+Alt+N）だとブレークポイントで止まってくれません。

でバック機能を利用することで指定したところで止まって変数の確認ができます。

### デバッグ設定

VS Codeのデバッグパネル（`Ctrl+Shift+D`）から以下の設定を選択できます：

#### 1. C++:Debug
- **用途**: 通常のデバッグ実行
- **動作**:
  - ビルドタスク（`buildC++`）を実行
  - GDBでデバッグ開始
  - デバッグ終了後、実行ファイルを自動削除

### ブレークポイントの設定

1. 行番号の左側をクリックしてブレークポイントを設定
2. F5でデバッグ開始
3. 変数のホバー、ウォッチ式、コールスタックなどを確認可能


## 設定ファイルの説明

### Dockerfile

Dockerイメージの定義ファイル。以下の処理を行います：

1. **ベースイメージ**: Ubuntu 25.10
2. **タイムゾーン設定**: Asia/Tokyo
3. **基本ツールインストール**: zsh, git, curl等
4. **C++環境構築**: g++-13, clang, clangd, gdb
5. **AtCoder Libraryインストール**: `/lib/ac-library`
6. **atcoder-cliインストール**: npm経由
7. **atcsインストール**: アーキテクチャに応じて自動選択

### .devcontainer/devcontainer.json

Dev Containerの設定ファイル：

- **ビルドコンテキスト**: プロジェクトルート
- **Dockerfile**: `../Dockerfile`を参照
- **VS Code拡張機能**: 自動インストール
  - CMake Tools
  - C/C++ Extension Pack
  - Code Runner
  - clangd

### .vscode/settings.json

#### エディタ設定

- **フォーマット**: 保存時自動フォーマット有効
- **タブサイズ**: C++は2スペース、Pythonは4スペース
- **フォーマッター**: clangd（C++）

#### Code Runner設定

- **C++実行コマンド**: `g++ -O2 -std=c++23 "$fileName" && ./a.out && rm ./a.out`
- **ターミナル実行**: 有効

#### clangd設定

- **C++標準**: `-std=gnu++2b`（C++23）
- **バックグラウンドインデックス**: 有効
- **clang-tidy**: 有効
- **補完スタイル**: detailed
- **フォールバックスタイル**: LLVM

#### オートコンプリート設定

競技プログラミング向けに、不要な補完を無効化：
- クラス、コンストラクタ、列挙型などの補完を無効化
- キーワード補完のみ有効

## 便利な機能

### テンプレートファイル

`template.cpp`には以下の機能が含まれています：

- **型エイリアス**: `ll`（long long）、`ld`（long double）、`vi`（vector<int>）、`vl`（vector<ll>）、`vvl`（2次元配列）、`vvvl`（3次元配列）、`vb`（vector<bool>）、`pl`（pair<ll,ll>）など
- **マクロ**:
  - `rep(i, n)`: `for (int i = 0; i < n; i++)`の短縮
  - `repn(i, num, n)`: `for (int i = num; i < n; i++)`の短縮
  - `per(i, n)`: 逆順のfor文
  - `pern(i, num, n)`: 逆順範囲のfor文
  - `all(v)`: `v.begin(), v.end()`の短縮
  - `pb`: `push_back`の短縮
  - `fi`, `se`: `first`, `second`の短縮
  - `LB(v, val)`, `UB(v, val)`, `BS(v, val)`: lower_bound、upper_bound、binary_searchの短縮
  - `MINE(v)`, `MAXE(v)`: min_element、max_elementの短縮
- **ユーティリティ関数**:
  - `yes()`, `YES()`, `Yes()`: 真偽値の出力（"yes"/"no"など）
  - `possible()`, `Possible()`, `POSSIBLE()`: 可能性の出力
  - `fast_io()`: 高速入出力の設定
  - `cinarr(v)`: 配列の一括入力
  - `print(...)`: 可変長引数での出力
  - `print_ld(x, precision)`: 固定小数点での出力
  - `printarr(v, isReverse)`: 配列の出力
  - `addv(v, loc, val)`: 配列要素の追加
- **その他の便利機能**:
  - `_pq<T>`: 最小値優先のpriority_queue
  - `chmin(a, b)`, `chmax(a, b)`: 最小値・最大値の更新
  - `So(v)`, `Sore(v)`: ソート関数
  - `binary_count(a)`: ビットカウント

### AtCoder Library (ACL)の使用

ACLは自動的にインクルードパスに含まれています：

```cpp
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
```

### atcoder-cli (acc)の使用

コンテスト管理ツール：

```bash
# コンテストの開始
acc new abc123

# 問題の提出
acc submit main.cpp

# テスト実行
acc test
```

詳細は[公式インストールガイド](http://tatamo.81.la/blog/2018/12/07/atcoder-cli-installation-guide/)を参照してください。

### atcsの使用

問題スクレイピングツール：

```bash
# 問題を取得
atcs https://atcoder.jp/contests/abc123/tasks/abc123_a
```

詳細は [AtCoder シンプルなスクレイピングツール「atcs」の紹介](https://qiita.com/tomyou666/items/6acf1f048b81a24da58b) を参照してください。

## ライセンス

このプロジェクトは [MIT License](LICENSE) の下で公開されています。

## 貢献

バグ報告や機能要望は、Issueでお知らせください。プルリクエストも歓迎します。

---

**Happy Coding! 🚀**
