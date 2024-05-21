#include<iostream>
#include<list>
// #include<vector>

using namespace std;

int main() {
    list<int> numbers {};

    for(int i = 1; i <= 10; i++) {
        numbers.push_back(i % 5);
    }
   

    //list<int>::iterator it = numbers.begin();

    // 5. element entfernen
    //advance(it, 4);

    //cout << *it << endl;

    // numbers.erase(it);
    // numbers.insert(it, 99);

    // numbers.clear();

    // numbers.erase(it);

    // numbers.remove(4);

    numbers.sort();

    for(int i : numbers) {
        cout << i << endl;
    }
}