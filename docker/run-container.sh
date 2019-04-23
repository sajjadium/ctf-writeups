#!/bin/bash

cd `dirname $0`

source common.sh

case "$(uname -s)" in
	Darwin)
        IP=`ipconfig getifaddr en0`
        xhost + $IP
    	;;

	Linux)
        xhost local:root
		;;
esac

docker start $CONTAINER
docker exec -it $CONTAINER /bin/bash

