#!/bin/bash

log_error() {
    echo "Error: $1"
}

writefile=$1
writestr=$2

if [ -z "$writefile" ]; then
    log_error "Argument 1: writefile is empty"
    exit 1
fi

if [ -z "$writestr" ]; then
    log_error "Argument 2: writestr is empty"
    exit 1
fi

mkdir -p $(dirname "$writefile")
echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    log_error "Unable to create the file '$writefile'"
    exit 1
fi	
