#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: $(basename $0) source_dir"
    exit 1
fi

SOURCE_DIR=$1

(cd $SOURCE_DIR; find . -type f) | while read F; do
    DIR_NAME=`dirname $F`
    if [ ! -d $DIR_NAME ]; then
        mkdir -p $DIR_NAME
        echo $DIR_NAME '->' $SOURCE_DIR/$DIR_NAME
    fi
    rm -f $F; ln -s $SOURCE_DIR/$F $F
done
echo
