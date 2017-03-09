#!/bin/bash
bldDir=$(dirname $0)/_build

if [ "$1" == "clean" ]
then
    rm -rf $bldDir
else
    mkdir $bldDir >/dev/null
    cd $bldDir
    cmake ..
    make
fi

