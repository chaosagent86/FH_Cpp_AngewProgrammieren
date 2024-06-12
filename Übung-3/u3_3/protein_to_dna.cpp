#include <iostream>
#include <map>
#include <fstream>

std::map<char, std::string> read_Codon_Table(std::string &i_filename);
void show_help();
std::string translate_Protein_to_DNA(const std::string &i_sequence_to_translate, const std::map<char, std::string> &i_codonTable);

int main(int argc, char *argv[]) {
    std::cout << "\n\n*********************************" << std::endl;
    std::cout << "*** Protein to DNA Translator ***" << std::endl;
    std::cout << "*********************************\n" << std::endl;

    std::string filename;
    std::string sequence_to_translate;

    bool arg_input_file = false;
    bool arg_input_sequence = false;


    if(argc < 2) {
        std::cerr << "Please privide --file <mapping_file> --sequence <DNA-sequence>" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "--help") {
            show_help();
            return -1;
        }
        if(std::string(argv[i]) == "--file") {
            if(i+1 < argc) {
                filename = argv[i+1];
                arg_input_file = true;
            } else {
                std::cerr << "Missing argument after --file !" << std::endl;
                return -1;
            }
        }
        if(std::string(argv[i]) == "--sequence") {
            if(i+1 < argc) {
                sequence_to_translate = argv[i+1];
                arg_input_sequence = true;
            } else {
                std::cerr << "Missing argument after --sequence !" << std::endl;
                return -1;
            }
        }
    } // end of for loop
    if(!arg_input_file || !arg_input_sequence) {
        std::cerr << "Please evaluate the provided parameters!" << std::endl;
        if(!arg_input_file)
            std::cerr << "Parameter --file is missing!" << std::endl;
        if(!arg_input_sequence)
            std::cerr << "Parameter --sequence is missing!" << std::endl;
        return -1;
    }

    std::cout << "Filename provided: \t\t" << filename << std::endl;
    std::cout << "DNA Sequence provided: \t\t" << sequence_to_translate << "\n" << std::endl;

    std::cout << "Trying to read in the mapping file ... " ;
    std::map<char, std::string> codon_Table = read_Codon_Table(filename);

    std::cout << "Translating everyting into Protein sequence ... " << std::endl;
    std::string dna_sequence = translate_Protein_to_DNA(sequence_to_translate, codon_Table);

    std::cout << "Translated DNA sequence:\t" << dna_sequence << std::endl;

    return 0;
}

//******************************************************

void show_help() {
    std::cout << "*************************************************************" << std::endl;
    std::cout << "--help \t shows this help" << std::endl;
    std::cout << "--file <mapping_file_name>" << std::endl;
    std::cout << "\t should contain the mapping information as followed:" << std::endl;
    std::cout << "\t <codon>\\t <aminoacid>" << std::endl;
    std::cout << "--sequence <amino_acid_sequence_to_translate>" << std::endl;
    std::cout << "*************************************************************" << std::endl  << std::endl;
}

//******************************************************

std::map<char, std::string> read_Codon_Table(std::string &i_filename) {
    std::string codon;
    char amino_Acid;
    std::map<char, std::string> codon_Table;
    std::ifstream file(i_filename);
    if(!file.is_open()) {
        std::cerr << "\nError! Could not open mapping file!" << std::endl;
        return codon_Table;
    }
    while (file >> codon >> amino_Acid) {
        codon_Table[amino_Acid] = codon;
    }
    file.close();

    std::cout << "done!" << std::endl;
    return codon_Table;
}

//******************************************************

std::string translate_Protein_to_DNA(const std::string &i_sequence_to_translate, const std::map<char, std::string> &i_codonTable) {
    std::string dna_sequence;
    for(char amino_acid : i_sequence_to_translate) {
        if (i_codonTable.find(amino_acid) != i_codonTable.end()) {
            dna_sequence += i_codonTable.at(amino_acid);
        }
    }
    return dna_sequence;
}