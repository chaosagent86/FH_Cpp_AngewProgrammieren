#include<iostream>
#include<vector>

using namespace std;

void test(vector<int> v) {
    cout << "test: " << v.size() << endl;
}

int main() {
    vector<int> numbers {};


    for(int i = 1; i <= 10; i++) {
        numbers.push_back(i);
    }
   

    vector<int>::iterator it = numbers.begin();

    // 5. element entfernen
    advance(it, 4);

    //cout << *it << endl;

    numbers.erase(it);
    numbers.insert(it, 99);

    // numbers.clear();

    for(int i : numbers) {
        cout << i << endl;
    }

    cout << numbers.size() << endl;

    test(numbers);
}