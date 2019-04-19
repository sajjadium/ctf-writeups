#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <Ubuntu Release>" >&2
    echo "       Ubuntu Release can be any supported version of the Ubuntu such as 16.04, 17.10, 18.04, 18.10, ..." >&2
    exit 1
fi

UBUNTU_RELEASE=$1
IMAGE="ctfium-${UBUNTU_RELEASE}"
CONTAINER=$IMAGE

