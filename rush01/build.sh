#!/bin/sh

# Place in repository root and make a folder called "tests" with the tester source and cases.
# This script will go into their ex00 to compile their program and then build the tester and run it.

echo "Testing norm..."
sleep 1
cd ex00 && norminette
echo "Compiling your program..."
sleep 1
cc -Wall -Wextra -Werror *.c -o rush-01
sleep 1
echo "Compiling and running tester..."
cd ../tests && cc tester.c -o tester
./tester ../ex00/rush-01 test.cases
cd ..
