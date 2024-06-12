#include <iostream>
#include <map>
#include <fstream>

std::map<std::string, char> read_Codon_Table(std::string &i_filename);
void show_help();
std::string translate_DNA_to_Protein(const std::string &i_sequence_to_translate, const std::map<std::string, char> &i_codonTable);

int main(int argc, char *argv[]) {
    std::cout << "\n\n*********************************" << std::endl;
    std::cout << "*** DNA to Protein Translator ***" << std::endl;
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

    //test if sequence is useful!
    if(sequence_to_translate.length() % 3 != 0) {
        std::cerr << "Sequence length should be a multiple of 3!" << std::endl;
        return -1;
    }

    std::cout << "Trying to read in the mapping file ... " ;
    std::map<std::string, char> codon_Table = read_Codon_Table(filename);

    std::cout << "Translating everyting into Protein sequence ... " << std::endl;
    std::string protein_sequence = translate_DNA_to_Protein(sequence_to_translate, codon_Table);

    std::cout << "Translated Protein sequence:\t" << protein_sequence << std::endl;

    return 0;
}

//******************************************************

void show_help() {
    std::cout << "*************************************************************" << std::endl;
    std::cout << "--help \t shows this help" << std::endl;
    std::cout << "--file <mapping_file_name>" << std::endl;
    std::cout << "\t should contain the mapping information as followed:" << std::endl;
    std::cout << "\t <codon>\\t <aminoacid>" << std::endl;
    std::cout << "--sequence <dna_sequence_to_translate>" << std::endl;
    std::cout << "*************************************************************" << std::endl  << std::endl;
}

//******************************************************

std::map<std::string, char> read_Codon_Table(std::string &i_filename) {
    std::string codon;
    char amino_Acid;
    std::map<std::string, char> codon_Table;
    std::ifstream file(i_filename);
    if(!file.is_open()) {
        std::cerr << "\nError! Could not open mapping file!" << std::endl;
        return codon_Table;
    }
    while (file >> codon >> amino_Acid) {
        codon_Table[codon] = amino_Acid;
    }
    file.close();

    std::cout << "done!" << std::endl;
    return codon_Table;
}

//******************************************************

std::string translate_DNA_to_Protein(const std::string &i_sequence_to_translate, const std::map<std::string, char> &i_codonTable) {
    std::string protein_Sequence;
    for (size_t i = 0; i < i_sequence_to_translate.length(); i += 3) {
        std::string codon = i_sequence_to_translate.substr(i, 3);
        if (i_codonTable.find(codon) != i_codonTable.end()) {
            protein_Sequence += i_codonTable.at(codon);
        }
    }
    return protein_Sequence;
}