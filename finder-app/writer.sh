#!/bin/sh

writefile="$1"
writestr="$2"

if [ $# -lt 2 ]; then
    echo "Error: Missing arguments."
    exit 1
else
    mkdir -p "$(dirname "$writefile")"

    echo "$writestr" >> "$writefile"
    if [ ! -f "$writefile" ]; then
        echo "Error: File could not be created."
        exit 1
    fi
fi

