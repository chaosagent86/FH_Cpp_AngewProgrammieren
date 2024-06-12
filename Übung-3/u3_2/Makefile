flags = -Wall -Wextra -std=c++11

all: compile link

compile:
	g++ -c $(flags) dna_to_protein.cpp

link: compile
	g++ -o dna_to_protein *.o

clean:
	rm *.o dna_to_protein

run_without:
	./dna_to_protein
	
run:
	./dna_to_protein --file mapping_DNA_Protein.txt --sequence ATGACATCGGGGGCCCACTGCAACCTATGA
