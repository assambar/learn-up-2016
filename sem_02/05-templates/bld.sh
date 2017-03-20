#!/bin/bash
bldDir=$(dirname $0)/_build

if [ "$1" == "clean" ]
then
    rm -rf $bldDir
else
    mkdir $bldDir 2>/dev/null
    cd $bldDir
    cmake ..
    make
fi

