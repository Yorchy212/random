#!/bin/bash

lista=$(ls)

for i in $lista
do
    if [ -x "$i" -a "$i" != "script.sh" ]
    then
        rm -rf "$i"
    fi
done