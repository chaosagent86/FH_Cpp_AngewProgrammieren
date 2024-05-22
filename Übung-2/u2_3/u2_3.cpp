#include <iostream>
#include <fstream>
#include <unordered_set>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2>\n";
        return 1;
    }

    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::unordered_set<std::string> wordsInFileOne;
    std::string word;
    std::unordered_set<std::string> commonWords;

    while (file1 >> word) {
        wordsInFileOne.insert(word);
    }

   while (file2 >> word) {
        if (wordsInFileOne.find(word) != wordsInFileOne.end()) {
            commonWords.insert(word);
        }
    }
    for (const auto& w : commonWords) {
        std::cout << w << '\n';
    }

    return 0;
}