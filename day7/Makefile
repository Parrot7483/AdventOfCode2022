CC=g++ 
CFLAGS=-std=c++20 -lfmt -Wall -fdiagnostics-color=always

make :
	@ $(CC)$(CFLAGS) src/main.cpp -o main 

run :
	@ cat input.txt | ./main

test : 
	@ cat test.txt | ./main

clean : 
	@ rm main
