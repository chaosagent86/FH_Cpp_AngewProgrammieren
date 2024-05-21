#include <set>
#include <iostream>

using namespace std;

int main() {

    set<int> numbers {};


    numbers.insert(4);
    numbers.insert(3);
    numbers.insert(4);


    cout << "count von 4 " << numbers.count(4) << endl;
    cout << "count von 7 " << numbers.count(7) << endl;


    for(int i : numbers) {
        cout << i << endl;
    }

    return 0;
}