#!/bin/bash

source common.sh

docker stop $IMAGE
docker rm -f $IMAGE
docker rmi -f $IMAGE

cat Dockerfile | sed "s/UBUNTU_RELEASE/${UBUNTU_RELEASE}/g" | docker build . -t $IMAGE --no-cache -f -

