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
xhost + $IP

docker start $CONTAINER
docker exec --privileged -it $CONTAINER /bin/bash

