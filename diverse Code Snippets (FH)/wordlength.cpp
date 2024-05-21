#include<iostream>
#include<fstream>
#include<map>

using namespace std;

int main(int argc, char* argv[]) {
     if(argc < 2) {
         cout << "Dateiname muss als Argument angegeben werden!";
         return 1;
     }

    ifstream inputFile((string)argv[1]);

    string word;
    map<int, int> wordCounts;

    while(!inputFile.eof() && inputFile >> word) {
        int len = word.length();

        if(wordCounts.count(len) > 0) {
            wordCounts[len]++;
        } else {
            wordCounts[len] = 1;
        }

        cout << word << endl;
    }

    for(pair<int, int> p : wordCounts) {
        cout << p.first << " - " << p.second << endl;
    }

    return 0;   
}