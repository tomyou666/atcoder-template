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

# C++, Python3, PyPy3の3つの環境想定
RUN apt-get update && \
    apt-get install -y \
        g++-13 \
        clang clangd \
        gdb \
        python3.13 python3-pip \
        pypy3 \
        nodejs npm && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 一般的なコマンドで使えるように設定
# e.g. python3.8 main.py => python main.py
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 30 && \
    update-alternatives --install /usr/bin/python python /usr/bin/python3.13 30 && \
    update-alternatives --install /usr/bin/pip pip /usr/bin/pip3 30 && \
    update-alternatives --install /usr/bin/pypy pypy /usr/bin/pypy3 30

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone --depth 1 https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# AtCoderでも使えるPythonライブラリをインストール
# RUN pip install -U pip --break-system-packages
RUN pip install \
    numpy scipy scikit-learn \
    numba networkx \
    black isort flake8 mypy \
    git+https://github.com/hinamimi/ac-library-python \
    git+https://github.com/hinamimi/python-sortedcontainers \
    online-judge-tools \
    --break-system-packages

# コンテスト補助アプリケーションをインストール
RUN npm install -g atcoder-cli
