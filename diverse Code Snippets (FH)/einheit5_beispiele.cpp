#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <time.h>  
using namespace std;


int getDoubleWords(set <string>& primarySet, set <string>& uniqueSet, string& filename) {
    ifstream inputFile (filename);
    string word;


        if (inputFile.is_open())
{
  cout<<"File successfully opened"<<endl;
}
else
{

 cout << "File could not be opened";
 return 0;
}

while (inputFile.eof() == false) { 
 inputFile >> word;
 if (primarySet.count(word) != 0) {
    if (uniqueSet.count(word) == 0)  {
        uniqueSet.insert(word);
        }
    }
 if (primarySet.count(word) == 0) {
    primarySet.insert(word);
    }
    
    }

    return 1;
}

void printResultSet(set <string>& uniqueSet) {
 cout<<"Double Values Result Set: "<<endl;
 for (auto i: uniqueSet)
    {cout<<i<<endl;
    };
 }



int getWordLenghts(string& filename) {

    ifstream inputFile (filename);
    string word;
    if (inputFile.is_open())
        {
         cout<<"File successfully opened"<<endl;
        }
    else
        {
        cout << "File could not be opened";
        return 0;
        }


    map<int, int> countMap{};

    while (inputFile.eof() == false) { 
        inputFile >> word;
        int wordLenght = word.length();
        countMap[wordLenght] += 1;
    
    }
    cout <<"Len , Count"<<endl;
    for(pair<int,int> len: countMap) { cout << len.first << " " << len.second <<"x" << endl; }
    return 1;
}



int randomNumber(int len, int i ){
    int min = 1, max = len;
    int range = max - min;
    srand(i);
    double random = rand() / (double)RAND_MAX; // [0..1]
    int randomInRange = round(min + random * range);
    return randomInRange;
}

void shuffleList(){

    list<int> numbers{1,2,8,9,10};
    int len = numbers.size();
    for(int i : numbers)
    {
        int pos1 = randomNumber(len, i*1000);
        int pos2 = randomNumber(len, i*5000000);
        numbers.remove(pos1);
        numbers.remove(pos2);
        numbers.push_back(pos1);
        numbers.push_front(pos2);
    }
    cout<<"Shuffeled Number Array: "<<endl;
    for (int i : numbers ){
        cout<<i<<endl;
    }
}


// Programm benötigt txt datei und gewünschtes Programm, also zb:  .a.out input.txt 1 bzw a.exe input.txt 1
// um programm 1 (doppelte wörter) aufzurufen
int main(int argc, char* argv[]) {

    string filename= argv[1];
    string command = argv[2];

    if (command == "1") { 
    cout<<"\nProgramm 1: Get double Words \n" <<endl;
    set <string> wordsPrimarySet{};
    set <string> doubleWordsUniqueSet{};
    int checkpoint = getDoubleWords(wordsPrimarySet,doubleWordsUniqueSet,  filename);
    if (checkpoint == 0) {return 0;}
    printResultSet(doubleWordsUniqueSet);
    }

    if (command == "2") { 
    cout<<"\nProgramm 2: Cout wordlenghts \n" <<endl;
    int checkpoint2 = getWordLenghts(filename);
    }
    
    if (command == "3") {
    cout<<"\nProgramm 3: Shuffle number list\n" <<endl;
    shuffleList();
    return 0;
    }
}