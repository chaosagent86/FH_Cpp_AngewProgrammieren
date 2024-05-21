#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream exampleFile;
    exampleFile.open("test.txt");
    // exampleFile << "Das ist eine Ausgabe." << endl;

    string word;

    // while (exampleFile.eof() == false)
    // {
    //     if (exampleFile >> word)
    //     {

    //         cout << "gelesen:" << word << endl;
    //     }
    // }

    if (exampleFile.is_open())
    {
        string line;
        while (getline(exampleFile, line))
        {
            cout << "Zeile gelesen: " << line << endl;
        }
    }
    else
    {
        cout << "Datei konnte nicht geöffnet werden!" << endl;
    }

    exampleFile.close();
}