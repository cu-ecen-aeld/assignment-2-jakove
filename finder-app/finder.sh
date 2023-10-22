#!/bin/bash

log_error () {
    echo "Error: $1"
}

filesdir=$1
searchstr=$2


if [ -z "$filesdir" ]; then
    log_error "Argument 1: filesdir is emtpy"
    exit 1
fi

if [ -z "$searchstr" ]; then
   log_error "Argument 2: searchstr is empty" 
   exit 1
fi

if [ ! -d "$filesdir" ]; then
    log_error "'$filesdir' is not a valid directory"
    exit 1
fi

number_of_files=$(find "$filesdir" -type f | wc -l)
number_of_lines=$(grep -r "$searchstr" "$filesdir" | wc -l) 

echo "The number of files are $number_of_files and the number of matching lines are $number_of_lines"

