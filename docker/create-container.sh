#!/bin/bash

source common.sh

docker stop $CONTAINER
docker rm -f $CONTAINER

OPTIONS=""

case "$(uname -s)" in
	Darwin)
		IP=`ipconfig getifaddr en0`
    	OPTIONS="--env=DISPLAY=$IP:0 -v /tmp/.X11-unix:/tmp/.X11-unix"
    	;;

	Linux)
   		OPTIONS="--env=DISPLAY -v $HOME/.Xauthority:/root/.Xauthority:rw"
		;;
esac

docker create \
    --name=$CONTAINER \
    -v $(realpath ../):/ctf \
    --net=host \
    --cap-add=SYS_PTRACE \
	$OPTIONS \
    -i -t $CONTAINER

docker start $CONTAINER

