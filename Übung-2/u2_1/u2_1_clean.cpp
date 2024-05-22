#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void ProcessFastaFile(const string& filePath);
void PrintHeaderAndSequence(const string& header, const string& sequence, map<char, int>& nucleotideCount);
void CountNucleotides(const string& sequence, map<char, int>& nucleotideCount);
void PrintNucleotideCounts(const map<char, int>& nucleotideCount);

int main() {
    string filePath = "file.fasta";
    ProcessFastaFile(filePath);
    return 0;
}

void ProcessFastaFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }
    string line;
    string currentHeader;
    string currentSequence = "";
    map<char, int> nucleotideCount;
    while (getline(file, line)) {
        if (line[0] == '>') {
            if (!currentSequence.empty()) {
                PrintHeaderAndSequence(currentHeader, currentSequence, nucleotideCount);
                currentSequence.clear();
            }
            currentHeader = line;
        } else {
            currentSequence += line;
        }
    }
    if (!currentSequence.empty()) {
        PrintHeaderAndSequence(currentHeader, currentSequence, nucleotideCount);
    }
    PrintNucleotideCounts(nucleotideCount);
}

void PrintHeaderAndSequence(const string& header, const string& sequence, map<char, int>& nucleotideCount) {
    cout << "Header: " << header << endl;
    cout << "Sequence: " << sequence << endl;
    CountNucleotides(sequence, nucleotideCount);
}

void CountNucleotides(const string& sequence, map<char, int>& nucleotideCount) {
    for (char nucleotide : sequence) {
        if (nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T') {
            nucleotideCount[nucleotide]++;
        }
    }
}

void PrintNucleotideCounts(const map<char, int>& nucleotideCount) {
    cout << "Nucleotide counts:" << endl;
    for (const auto& pair : nucleotideCount) {
        cout << pair.first << " n=" << pair.second << endl;
    }
}
