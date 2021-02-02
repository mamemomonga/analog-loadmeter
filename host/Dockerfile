FROM golang:1.15.7-alpine

RUN set -xe && \
	apk add git make

ENV GOPATH=/go
ENV GOBIN=/go/bin
ENV GO111MODULE=on

ADD . /g/
WORKDIR /g
RUN set -xe && \
	make clean && \
	make
