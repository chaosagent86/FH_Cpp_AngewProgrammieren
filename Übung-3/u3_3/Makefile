flags = -Wall -Wextra -std=c++11

all: compile link

compile:
	g++ -c $(flags) protein_to_dna.cpp

link: compile
	g++ -o protein_to_dna *.o

clean:
	rm *.o protein_to_dna

run_without:
	./protein_to_dna
	
run:
	./protein_to_dna --file mapping_DNA_Protein.txt --sequence MTSGAHCNL
