#include <iostream>
#include <fstream>
#include <unordered_set>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        std::cerr << "Provide two files, e.g. '.\\programm first_file.txt second_file.txt'" << std::endl;
        return -1;
    }
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening files.\n";
        return -1;
    }

    std::unordered_set<std::string> wordsInFile1;
    std::string word;
    std::unordered_set<std::string> commonWords;

    std::cout << wordsInFile1 << std::endl;
    std::cout << word << std::endl;

    while (file2 >> word) {
        if (wordsInFile1.find(word) != wordsInFile1.end()) {
            commonWords.insert(word);
        }
    }

    //std::cout << commonWords << std::endl;

    for(auto w : commonWords) {
        std::cout << w << std::endl;
    }

    return 0;
}