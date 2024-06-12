#include<iostream>
#include<cmath>

using namespace std;



long lcg(long x, long a, long c, long m) {
    return (a * x + c) % m;
}

int main() {
    // x_n = (a*x_(n-1) + c) mod m

    long a = 1103515245;
    long m = pow(2, 31);
    long c = 12345;
    
    long x = time(NULL);

    int arr[10] = {0};

    for(int i = 0; i < 1000000; i++) {
        x = lcg(x, a, c, m);

        // zahl >= 0 <= 9
        long z = x % 10;

        arr[z]++;

        //cout << "Nächste ZZ: " << z << endl;
    }

    for(int i = 0; i < 10; i++) {
        cout << i << " " << arr[i] << endl;
    }

    return 0;
}