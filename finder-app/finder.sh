#!/bin/sh

filesdir=$1
searchstr=$2

if [ $# -lt 2 ]; then
    echo "Error: Missing arguments."
    exit 1
else
    if [ ! -d "$filesdir" ]; then
        echo "${filesdir} does not represent a directory"
        exit 1
    else
        X=$(( $(ls "$filesdir" -R | wc -l) - 1 ))
        Y=$(grep -r "$searchstr" "$filesdir" | wc -l)
        echo "The number of files are ${X} and the number of matching lines are ${Y}"
    fi
fi

