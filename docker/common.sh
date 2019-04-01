#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <Architecture> <Ubuntu Release>" >&2
    echo "       Architecture:   amd64, i386, arm32v7, arm64v8" >&2
    echo "       Ubuntu Release: 16.04, 17.10, 18.04, 18.10" >&2
    exit 1
fi

ARCHITECTURE=$1
UBUNTU_RELEASE=$2
IMAGE="ctf-${ARCHITECTURE}-${UBUNTU_RELEASE}"
CONTAINER=$IMAGE

cd `dirname $0`

