#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 ARCH(amd64,i386,arm32v7,arm64v8) UBUNTU_VERSION(16.04,17.10,18.04,18.10)" >&2
    exit 1
fi

ARCHITECTURE=$1
UBUNTU_VERSION=$2
CONTAINER="ctf-${ARCHITECTURE}-${UBUNTU_VERSION}"

cd `dirname $0`

IP=`ipconfig getifaddr en0`

docker stop $CONTAINER
docker rm -f $CONTAINER

docker create \
    --name=$CONTAINER \
    -v $(realpath ../../):/ctf \
    --net=host \
    --env=DISPLAY=$IP:0 \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --cap-add=SYS_PTRACE \
    -i -t $CONTAINER

docker start $CONTAINER

