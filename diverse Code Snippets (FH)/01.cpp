#include <iostream>

using namespace std;

int main() {

    //int i;

    // cout << sizeof(signed long long int) << endl;

    // cout << "float" << sizeof(float) << endl;
    // cout << "double" << sizeof(double) << endl;
    // cout << "long double" << sizeof(long double) << endl;


    // int a = 0;
    // int b = 0;
    // int arr[4] = {1, 2, 3, 4};
    // int d = 0;
    // int e = 0;
    // int arr2[4] = {5, 6, 7, 8};


    // cout << " a   " << a << endl;
    // cout << " b   " << b << endl;    
    // cout << " arr " << arr << endl;    
    // cout << " d   " << (long)&d<< endl;
    // cout << " e   " << (long)&e<< endl;
    // cout << " ar2 " << (long)&arr2 << endl;    

    // arr[5] = 9;

    // cout << "arr2[0] " << arr2[1] << endl;


    // long i = 27;

    // int *p = (int*)&i;

    // cout << *p << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int *p = arr;

    for(int j = 0; j < 4; j++) {
        cout << arr[j] << " ";
    }
cout << endl;


    // 
    cout << ++*p << endl;



    for(int j = 0; j < 4; j++) {
        cout << arr[j] << " ";
    }
cout << endl;


    int i;

    //int len = sizeof(arr) /sizeof(int);


    // 01 00 00 00   10 00 00 00


    // int *p = &i;

    // if(p) {
    //   cout << *p << endl;
    // }
    // long *p = (long*)arr;

    // cout << *(p+1) << endl;

    //int len = sizeof(p) /sizeof(int);


    // cout << "len" << len << endl;


    // for(int j = 0; j < 10000; j++) {
    //     cout << "arr[" << j << "] = " << arr[j] << endl;
    // }

    // int *p = i;


    return 0;
}