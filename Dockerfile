# Ubuntuの公式コンテナを軸に環境構築
FROM ubuntu:23.10

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive
# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo
RUN ln -sf /usr/share/zoneinfo/Asia/Tokyo /etc/localtime

# インフラを整備
RUN apt-get update && \
    apt-get install -y zsh time tzdata tree git curl

# デフォルトシェルをZ shellにする
RUN chsh -s /bin/zsh

# C++, Python3, PyPy3の3つの環境想定
RUN apt-get install -y gcc-13
RUN apt-get install -y g++-13
RUN apt-get install -y clang
RUN apt-get install -y gdb
# 3.11.4がインストールされる
RUN apt-get install -y python3.11
RUN apt-get install -y python3-pip
RUN apt-get install -y pypy3
RUN apt-get install -y nodejs
RUN apt-get install -y npm

# 一般的なコマンドで使えるように設定
# e.g. python3.8 main.py => python main.py
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 30 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 30 && \
    update-alternatives --install /usr/bin/python python /usr/bin/python3.11 30 && \
    update-alternatives --install /usr/bin/pip pip /usr/bin/pip3 30 && \
    update-alternatives --install /usr/bin/pypy pypy /usr/bin/pypy3 30

# AtCoderでも使えるPythonライブラリをインストール
RUN pip install -U pip --break-system-packages && \
    pip install numpy scipy scikit-learn \
    numba networkx black isort flake8 mypy --break-system-packages

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# Pythonでの競技プログラミング用データ構造をインストール
RUN pip install git+https://github.com/hinamimi/ac-library-python --break-system-packages && \
    pip install git+https://github.com/hinamimi/python-sortedcontainers --break-system-packages

# コンテスト補助アプリケーションをインストール
RUN pip install online-judge-tools --break-system-packages
RUN npm install -g atcoder-cli
