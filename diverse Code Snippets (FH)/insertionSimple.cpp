#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

  srand(time(nullptr));

  int numbers[15];

  for(int i = 0; i < 15; i++) {
    int nr = rand() % 101;
    numbers[i] = nr;
  }

  // Print
  for(int i = 0; i < 15; i++){
    cout << numbers[i] << " ";
  }
  cout << endl;

  int sorted[15];
  for(int i = 0; i < 15; i++) {
    // Kleinstes Element suchen
    int min = -1, minIndex = -1;
    for(int j = 0; j < 15; j++) {
      if(numbers[j] == -1) {
        continue;
      }

      if(min == -1 || min > numbers[j]) {
        min = numbers[j];
        minIndex = j;
      }
    }

    if(minIndex > -1) {
      numbers[minIndex] = -1;
    }

    sorted[i] = min;

  }

  // Print
  for(int i = 0; i < 15; i++){
    cout << numbers[i] << " ";
  }
  cout << endl;

  // Print
  for(int i = 0; i < 15; i++){
    cout << sorted[i] << " ";
  }
  cout << endl;

  return 0;
}