#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: $(basename $0) openssl_source"
    exit 1
fi

OPENSSL_SOURCE=$1

(cd $OPENSSL_SOURCE; find . -type f) | while read F; do
    DIR_NAME=`dirname $F`
    if [ ! -d $DIR_NAME ]; then
        mkdir -p $DIR_NAME
        echo $DIR_NAME '->' $OPENSSL_SOURCE/$DIR_NAME
    fi
    rm -f $F; ln -s $OPENSSL_SOURCE/$F $F
done
echo
make -f Makefile.org clean
