#include <map>
#include <iostream>

using namespace std;

int main() {
    map<string, int> words {};

    words["test"] = 1;
    words["abcd"] = 2;
  
    // words["test"] = 25;
    // words.insert(pair<string, int>("test", 25));

    for(pair<string, int> p : words) {
        cout << p.first << endl;
        cout << p.second << endl;
    }

    return 0;
}