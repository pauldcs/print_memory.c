#!/bin/bash

set -x -e
make prod
ln -s xdp "/usr/local/bin/xdp"