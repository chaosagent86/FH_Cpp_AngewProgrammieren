#include <iostream>

using namespace std;


int add(int a, int b, int c = 0, int d = 0);



void increment(const int &i) {
    i = i + 1;
}


void print(int arr[], size_t size) {
    //cout << "len " << sizeof(arr) / sizeof(*arr) << endl;

    for(int i = 0; i < size; i++) {
        cout << arr[i];
    }
}


int main(){

    // int sum = add(1,2,3);

    // cout << sum;


    // int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    // cout << "len " << sizeof(arr) / sizeof(*arr) << endl;
    // print(arr);

    int a = 5;
    increment(a);
    cout << a << endl;

    return 0;
}

int add(int a, int b, int c, int d) {
   return a+ b + c +d; 
}


