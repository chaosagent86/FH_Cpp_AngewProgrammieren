#include <iostream>

using namespace std;

int main()
{
    int a[] = {1, 2, 3};
    string s = "abc";

    for (size_t i = 0; i < s.length(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}