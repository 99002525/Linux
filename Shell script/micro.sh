#!/bin/bash

: '
This is an example to read fields in a file
'

FILE_PATH="Input.csv"
RESULT_FILE="Results.csv"

while IFS=',' read -r f1 f2 REPO
do
    [[ $f1 != 'Name' ]] && echo "$f1"
    [[ $f2 != 'Email ID' ]] && echo "$f2"
    if [ "$REPO" != 'Repo link' ]; then
        repo=$REPO
        git clone "$REPO"
        if [ $? -eq 0 ]; then
            clone="Clone success"
        else
            clone="Clone Failure"
        fi
        REPO=`echo "$REPO" | cut -d'/' -f5`
        echo "REPO = $REPO"
        make -C "$REPO"
        if [ $? -eq 0 ]; then
            bu="Build success"
        else
            bu="Build Failure"
        fi
        ERR=`cppcheck "$REPO" | grep 'error' | wc -l`
        if [ $? -eq 0 ]; then
            er="$ERR"
        fi
        make test -C $REPO
        EXE=`find "$REPO" -name "Test*.out"`
        valgrind "./$EXE" 2>log.txt
        STR=$( tail -n 1 log.txt )
        val=$(echo ${STR:24:3})
        verr="$val"
        printf "$f1,$f2,$repo,$clone,$bu,$er,$verr\n" >> $RESULT_FILE
    fi
done < "${FILE_PATH}"

IFS=' '
