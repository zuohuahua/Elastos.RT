#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Symbolic link all the files (including files in subdirectories) in source_dir"
    echo "to current working directory. Create subdirectories if necessary."
    echo
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
