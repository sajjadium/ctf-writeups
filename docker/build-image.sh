#!/bin/bash

source common.sh

docker stop $IMAGE
docker rm -f $IMAGE
docker rmi -f $IMAGE

cat Dockerfile | sed -r "s/UBUNTU_RELEASE/${UBUNTU_RELEASE}/g" | sed -r "s/ARCHITECTURE/$ARCHITECTURE/g" | docker build . -t $IMAGE -f -

