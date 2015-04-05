#!/bin/bash

timestamp=$1
image_dir="./captures"

fswebcam -r 1280x960 ${image_dir}/$1.jpg
rc=$?
exit $rc