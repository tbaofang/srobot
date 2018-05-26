#!/bin/sh

cd build && rm * -rf && cmake .. && make && ./devel/lib/dm1/main
