#include <iostream>

using namespace std;

class Person
{
  public:
  string firstName;
  int year;

  Person *next = nullptr;

  Person(string firstName, int year) {
    this->firstName = firstName;
    this->year = year;

    cout << "## created: " << getName() << endl;
  }

  string getName() {
    return firstName + " (" + to_string(year) + ")";
  }
};

void addPerson(string firstName, int year, Person* last);
void printRegister(Person *personRegister);

int main()
{
  Person personRegister("REGISTER", 0);

  addPerson("Alice", 2000, &personRegister);
  addPerson("Bob", 1999, &personRegister);
  addPerson("Clare", 2001, &personRegister);

  addPerson("Dora", 1999, &personRegister);
  addPerson("Emil", 2000, &personRegister);

  printRegister(&personRegister);
  
  return 0;
}

void addPerson(string firstName, int year, Person* last)
{
  Person *newPerson = new Person(firstName, year);
  Person* current = last;

  // Insert at the end
//   while(current->next)
//   {
//      current = current->next;
//   }

  // current->next = newPerson;

  // Insert by correct year
  while(current->next && current->next->year < year) {
    current = current->next;
  }

  if(current -> next) {
    newPerson -> next = current -> next;
  }

  current -> next = newPerson;
}

void printRegister(Person *personRegister) {
  Person *current = personRegister;
  cout << "Complete Register: ";
  while(current != nullptr) {
    cout << current -> getName() << " - ";
    current = current -> next;
  }
  cout << endl;
}