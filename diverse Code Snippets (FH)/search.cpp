#include <fstream>
#include <iostream>

using namespace std;

string normalize(string s)
{
    string result = "";

    // for(size_t i = 0; i < s.length(); i++) {
    //     char c = s[i];
    //     // ...
    // }

    // Alternative Iterator-Syntax (for-each):
    for (auto c : s)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            result += toupper(c);
        }
    }

    return result;
}

int main()
{
    cout << "Geben Sie das gesuchte Wort an: ";

    string search;
    cin >> search;
    search = normalize(search);

    ifstream file("test.txt");
    if (file.is_open())
    {

        string current;
        int count = 0;
        while (!file.eof() && file >> current)
        {
            // cout << "akt: " << current << endl;

            current = normalize(current);
            if (current == search)
            {
                count++;
                // cout << "WORT GEFUNDEN" << endl;
            }
        }

        cout << "Das Wort wurde " << count << " mal gefunden." << endl;
    }
    else
    {
        file.close();
    }

    return 0;
}