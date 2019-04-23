#!/bin/bash

cd `dirname $0`

source common.sh

docker stop $CONTAINER
docker rm -f $CONTAINER

OPTIONS=""

case "$(uname -s)" in
	Darwin)
		IP=`ipconfig getifaddr en0`
    	OPTIONS="-e DISPLAY=$IP:0"
    	;;

	Linux)
   		OPTIONS="-e DISPLAY=$DISPLAY"
		;;
esac

docker create \
    --name=$CONTAINER \
    -v $(realpath ../):/ctf \
    --net=host \
    --cap-add=SYS_PTRACE \
    --privileged \
	$OPTIONS \
    -i -t $CONTAINER

docker start $CONTAINER

