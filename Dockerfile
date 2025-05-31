FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    wget \
    software-properties-common && \
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | apt-key add - && \
    apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' && \
    apt-get update && \
    apt-get install -y cmake

WORKDIR /app

COPY . /app/

RUN cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install && \
    cmake --build _build && \
    cmake --build _build --target install

WORKDIR /app/_install/bin

ENV LOG_PATH=/home/logs/log.txt

VOLUME ["/home/logs"]

ENTRYPOINT ["./hello_world"]
