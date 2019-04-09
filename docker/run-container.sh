#!/bin/bash

cd `dirname $0`

source common.sh

if [ "$(uname -s)" == "Darwin" ]; then
	IP=`ipconfig getifaddr en0`
    xhost + $IP
fi

docker start $CONTAINER
docker exec --privileged -it $CONTAINER /bin/bash

