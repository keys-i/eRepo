#!/bin/bash
# For loop
for i in 1 2 3; do
    echo "Number $i"
done

# While loop
while [ $i -le 5 ]; do
    echo "Number $i"
    i=$((i+1))
done

# Until loop
until [ $i -le 0 ]; do
    echo "Number $i"
    i=$((i-1))
done
