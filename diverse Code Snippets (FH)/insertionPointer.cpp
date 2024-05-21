#include <iostream>
#include <ctime>

using namespace std;

void printArray(int* arr, size_t size);
void fillWithRandomNumbers(int* arr, size_t size);

void printPointerArray(int** arr, size_t size);

bool isPointerInArray(int *p, int* arr[], size_t size);

int main() {
  srand(time(nullptr));

  int arr[5] = {3, 2, 4, 1, 1};
  size_t s = sizeof(arr) / sizeof(*arr);

  fillWithRandomNumbers(arr, s);
  printArray(arr, s);


  int *sorted[5] = {nullptr};

  // Sortieren ...
  for(size_t i = 0; i < s; i++) {
    // Kleinstes Element finden, das noch nicht im sortierten Array ist

    int *smallest = nullptr;

    for(size_t j = 0; j < s; j++) {
      // gibt's schon einen Pointer auf dieses Element, dann ignorieren
      if(isPointerInArray(arr + j, sorted, s)) {
        continue;
      }

      if(!smallest) {
        smallest = arr + j;
        continue;
      }

      if(arr[j] < *smallest) {
        smallest = arr + j;
      }
    }

    // kleinstes element gefunden ...
    sorted[i] = smallest;

    cout <<"smallest" << *smallest << endl;

  }

  cout << endl;
  //printArray(sorted, s);

  printPointerArray(sorted, s);
  // for(size_t i = 0; i < s; i++){
  //   cout << *sorted[i] << " ";
  // }
}

bool isPointerInArray(int *p, int* arr[], size_t size) {
  for(size_t k = 0; k < size; k++) {
    if(arr[k] == p) {
      return true;
    }
  }
  return false;
}

void printArray(int* arr, size_t size) {
  for(size_t i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printPointerArray(int** arr, size_t size) {
  for(size_t i = 0; i < size; i++){
    cout << *arr[i] << " ";
  }
  cout << endl;
}

void fillWithRandomNumbers(int* arr, size_t size) {
  for(size_t i = 0; i < size; i++){
    arr[i] = rand() % 100;
  }
}
