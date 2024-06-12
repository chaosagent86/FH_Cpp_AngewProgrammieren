flags = -Wall -Wextra -std=c++11

all: compile link run
compile:
	g++ -c $(flags) gc_gehalt.cpp

link: compile
	g++ -o gc_gehalt *.o

clean:
	rm *.o gc_gehalt

run:
	./gc_gehalt --input input.txt --output output.txt
