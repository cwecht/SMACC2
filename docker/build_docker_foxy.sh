#!/bin/sh
DIR="$(dirname "$(realpath "$0")")"
echo $DIR
./build_docker.sh foxy foxy