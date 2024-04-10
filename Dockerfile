FROM ubuntu:noble-20240225

WORKDIR /app

RUN apt-get -y update && \
    apt-get -y install gcc make  python3

COPY . .

RUN make

CMD ["./pipex"]
