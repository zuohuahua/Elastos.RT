#!/bin/bash

if [[ $# -lt 4 ]]; then
    echo Usage: $0 archive_script.ar libcombined.a liba.a libb.a ...
    exit 1
fi

OUTPUT_FILE=$1
shift
echo CREATE $1 > $OUTPUT_FILE
shift

for item in "$@"
do
    echo ADDLIB $item >> $OUTPUT_FILE
done
echo SAVE >> $OUTPUT_FILE
echo END >> $OUTPUT_FILE
