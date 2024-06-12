#include <iostream>

using namespace std;


class Person {

    public:
        string name;
        uint yearOfBirth;

        Person(string name, uint yearOfBirth): name(name), yearOfBirth(yearOfBirth) { };

        void print() {
            cout << "Person " << name << " " << yearOfBirth << endl;
        }
};

int main() {
    Person* persons[10] = {};
    size_t len = 10;
    
    string action;
    while(true) {
        cout << "Welche Aktion? (h, a, e)" << endl
             << "  h ... hinzufügen" << endl
             << "  l ... löschen" << endl
             << "  a ... ausgeben" << endl
             << "  e ... exit/beenden" << endl;
            
        if(cin >> action && action != "e") {
            cout << endl;

            if(action == "h") {
                cout << "--- Person hinzufügen ---" << endl;

                string name;
                uint yearOfBirth;
                cout << "Name eingeben: ";
                cin >> name;
                cout << "Geburtsjahr eingeben: ";
                cin >> yearOfBirth;

                for(size_t i = 0; i < len; i++) {

                    // Hinten dran einfügen
                    // if(persons[i] == nullptr) {
                    //     persons[i] = new Person(name, yearOfBirth);
                    //     break;
                    // }

                    // Sortiert einfügen
                    if(persons[i] == nullptr || persons[i]->yearOfBirth > yearOfBirth) {
                        for(size_t j = len - 1; j > i; j--) {
                            persons[j] = persons[j - 1];
                        }

                        persons[i] = new Person(name, yearOfBirth);
                        break;
                    }

                }
            }  else if(action == "l") {
                cout << "--- Person löschen ---" << endl;

                string name;
                cout << "Name eingeben: ";
                cin >> name;

                for(size_t i = 0; i < 10; i++) {
                    if(persons[i] && persons[i]->name == name) {
                        for(size_t j = i; j < len - 1; j++) {
                            persons[i] = persons[j];
                        }
                        persons[len-1] = nullptr;
                                                
                        // Nur 1. Person mit diesem Namen löschen.
                        break;
                    }
                }

            } else if(action == "a") {
                cout << "--- Personen ausgeben ---" << endl;
                for(int i = 0; i < 10; i++) {
                    if(persons[i]) {
                        cout << i << " ";
                        persons[i]->print();
                    }
                }

            }

            cout << "---------" << endl;

        } else {
            return 0;
        }
    }

    return 0;
}