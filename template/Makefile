CC=g++ 
CFLAGS=-std=c++20 -lfmt -Wall -fmessage-length=60 -fdiagnostics-color=always

part1 :
	@ $(CC)$(CFLAGS) src/shared.cpp src/part1.cpp -o main 

part2 :
	@ $(CC)$(CFLAGS) src/shared.cpp src/part2.cpp -o main

run :
	@ cat input.txt | ./main

test : 
	@ cat test.txt | ./main

clean : 
	@ rm main
