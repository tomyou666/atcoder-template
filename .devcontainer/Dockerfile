# Ubuntuの公式コンテナを軸に環境構築
FROM ubuntu:25.10

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive
# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo
RUN ln -sf /usr/share/zoneinfo/Asia/Tokyo /etc/localtime

# インフラを整備
RUN apt-get update && \
    apt-get install -y zsh time tzdata tree git curl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# デフォルトシェルをZ shellにする
SHELL ["/bin/zsh", "-c"]

# C++, の3つの環境想定
RUN apt-get update && \
    apt-get install -y \
        g++-13 \
        clang clangd \
        gdb \
        nodejs npm && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 一般的なコマンドで使えるように設定
# e.g. g++-13 => g++
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 30

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone --depth 1 https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# コンテスト補助アプリケーションをインストール
RUN npm install -g atcoder-cli

# スクレイピングツール「atcs」をインストール (アーキテクチャごとにURLを変更)
RUN ARCH=$([ "$(uname -m)" = "aarch64" ] && echo "arm64" || echo "amd64") && \
    curl -L "https://github.com/tomyou666/atcoder-scraper/releases/latest/download/atcs-linux-${ARCH}" -o atcs && \
    chmod +x atcs && \
    mv atcs /usr/local/bin/atcs

