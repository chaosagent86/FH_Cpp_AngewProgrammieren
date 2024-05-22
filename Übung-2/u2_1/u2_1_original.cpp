#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void macheDingeMitDatei(string dateipfad) {
    ifstream datei(dateipfad);
    string z;
    string h;
    string s = "";
    map<char, int> nC;
    while (getline(datei, z)) {
        if (z[0] == '>') {
            if (!s.empty()) {
                cout << "Header: " << h << endl;
                cout << "Sequence: " << s << endl;
                for (char n : s) {
                    if (n == 'A' || n == 'C' || n == 'G' || n == 'T') {
                        nC[n]++;
                    }
                }
                s = "";
            }
            h = z;
        } else {
            s += z;
        }
    }
    if (!s.empty()) {
        cout << "Header: " << h << endl;
        cout << "Sequence: " << s << endl;
        for (char n : sequence) {
            if (n == 'A' || n == 'C' || n == 'G' || n == 'T') {
                nC[n]++;
            }
        }
    }
    cout << "Anzahl Nukleotide:" << endl;
    for (auto& pair : nC) {
        cout << pair.first << " n=" << pair.second << endl;
    }
}

int main() {
    string dateipfad = "C:\\path\\to\\file.fasta";
    macheDingeMitDatei(dateipfad);
    return 0;
}
