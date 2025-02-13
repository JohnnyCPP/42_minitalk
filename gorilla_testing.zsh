#!/bin/zsh

# this script simplifies testing the client-server transmission, 
# sending a message to the server 'n' times
#
# the "pid" must be set every time, as the server pid changes

n=20
pid=1710314
message=""
times=10
piece_to_concat="aaaaa"

for ((i=1; i<=times; i++)); do
	message+=$piece_to_concat
done

for i in {1..$n}; do
	./client $pid $message
done
