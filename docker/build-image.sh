#!/bin/bash

# https://github.com/multiarch/qemu-user-static/releases

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 ARCH(amd64,i386,arm32v7,arm64v8) UBUNTU_VERSION(16.04,17.10,18.04,18.10)" >&2
    exit 1
fi

ARCHITECTURE=$1
UBUNTU_VERSION=$2
IMAGE="ctf-${ARCHITECTURE}-${UBUNTU_VERSION}"

cd `dirname $0`

docker stop $IMAGE
docker rm -f $IMAGE
docker rmi -f $IMAGE

cat Dockerfile | sed -r "s/UBUNTU_VERSION/${UBUNTU_VERSION}/g" | sed -r "s/ARCHITECTURE/$ARCHITECTURE/g" | docker build . -t $IMAGE -f -

