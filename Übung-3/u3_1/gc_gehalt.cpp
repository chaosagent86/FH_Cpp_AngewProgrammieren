#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

std::vector<std::string> read_input_file(std::string &i_input_filename);
void write_output_file_initial(const std::string &i_output_filename);
void write_output_file_attach_mode(float i_GC_content_rounded, const std::string &i_sequence, const std::string &i_output_filename);
void show_help();

int main(int argc, char *argv[]) {
    std::cout << "\n\n*********************" << std::endl;
    std::cout << "*** GC Calculator ***" << std::endl;
    std::cout << "*********************\n" << std::endl;

    std::string input_filename;
    std::string output_filename;

    bool arg_input_file = false;
    bool arg_output_file = false;


    if(argc < 2) {
        std::cerr << "Pleae provide input and output file. If you need help, restart with --help" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "--help") {
            show_help();
            return -1;
        }
        if(std::string(argv[i]) == "--input") {
            if(i+1 < argc) {
                input_filename = argv[i+1];
                arg_input_file = true;
            } else {
                std::cerr << "Missing argument after --input !" << std::endl;
                return -1;
            }
        }
        if(std::string(argv[i]) == "--output") {
            if(i+1 < argc) {
                output_filename = argv[i+1];
                arg_output_file = true;
            } else {
                std::cerr << "Missing argument after --output !" << std::endl;
                return -1;
            }
        }
    } // end of for loop

    if(!arg_input_file || !arg_output_file) {
        std::cerr << "Please evaluate the provided parameters!" << std::endl;
        if(!arg_input_file)
            std::cerr << "Parameter --input is missing!" << std::endl;
        if(!arg_output_file)
            std::cerr << "Parameter --output is missing!" << std::endl;
        return -1;
    }

    std::cout << "Input-Filename provided: \t" << input_filename << std::endl;
    std::cout << "Output-Filename provided: \t" << output_filename << std::endl << std::endl;

    auto sequences_vector = read_input_file(input_filename);
    write_output_file_initial(output_filename);

    for(auto current_sequence : sequences_vector) {
        if(current_sequence.empty()) // sollte nie eintreten eigentlich
            continue;
        float GC = 0;
        float GC_content = 0;
        for(auto character : current_sequence) {
            if(character == 'g' || character == 'c')
                GC++;
        }
        GC_content = GC * 100 / current_sequence.length();
        int rounded_GC_content = static_cast<int>(std::round(GC_content));
        write_output_file_attach_mode(rounded_GC_content, current_sequence, output_filename);
    }

    return 0;
}

//******************************************************

void show_help() {
    std::cout << "*************************************************************" << std::endl;
    std::cout << "--help \t shows this help" << std::endl;
    std::cout << "--input <input_file>\t should contain a fasta file (dna!) without header" << std::endl;
    std::cout << "--output <output_file>\tThe file were everything is written" << std::endl;
    std::cout << "*************************************************************" << std::endl  << std::endl;
}

//******************************************************

std::vector<std::string> read_input_file(std::string &i_input_filename) {
    std::ifstream input_file(i_input_filename);
    std::vector<std::string> sequences;
    std::string current_sequence;

    if(!input_file.is_open()) {
        std::cerr << "\nError! Could not open input file!" << std::endl;
        return sequences;
    }
    while (input_file >> current_sequence)
        sequences.push_back(current_sequence);
    input_file.close();
    return sequences;
}

//******************************************************

void write_output_file_initial(const std::string &i_output_filename) {
    std::ofstream output_file;
    output_file.open(i_output_filename, std::ios::out);
    output_file.close();
}

//******************************************************

void write_output_file_attach_mode(float i_GC_content_rounded, const std::string &i_sequence, const std::string &i_output_filename) {
    std::ofstream output_file;
    output_file.open(i_output_filename, std::ios::app);
    output_file << i_GC_content_rounded << " " << i_sequence << std::endl;
    output_file.close();
    std::cout << "Writen: " << i_GC_content_rounded << " " << i_sequence << std::endl;
}