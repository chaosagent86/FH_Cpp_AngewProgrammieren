#include <iostream>
#include <vector>

bool isStopCodon(const std::string& codon) {
    return codon == "UAG" || codon == "UGA" || codon == "UAA";
}

std::vector<std::string> findORFs(const std::string& rnaSequence) {
    std::vector<std::string> orfs;
    size_t seqLength = rnaSequence.length();
    for (size_t i = 0; i < seqLength - 2; i++) {
        if (rnaSequence.substr(i, 3) == "AUG") {
            for (size_t j = i + 3; j < seqLength - 2; j += 3) {
                std::string codon = rnaSequence.substr(j, 3);
                if (isStopCodon(codon)) {
                    orfs.push_back(rnaSequence.substr(i, j - i + 3));
                    break;
                }
            }
        }
    }
    return orfs;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " RNA_SEQUENCE" << std::endl;
        return 1;
    }
    std::string rnaSequence = argv[1];
    std::vector<std::string> orfs = findORFs(rnaSequence);
    for (const std::string& orf : orfs) {
        std::cout << orf << std::endl;
    }
    return 0;
}
