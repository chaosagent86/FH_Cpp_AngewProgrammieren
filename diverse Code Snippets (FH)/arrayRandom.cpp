#include <iostream>
#include <ctime>

using namespace std;

void printArray(int* arr, size_t size);
void fillWithRandomNumbers(int* arr, size_t size);

int main() {
  srand(time(nullptr));

  int arr[10];
  size_t s = sizeof(arr) / sizeof(*arr);

  printArray(arr, s);
  fillWithRandomNumbers(arr, s);
  cout << endl;
  printArray(arr, s);
}

void printArray(int* arr, size_t size) {
  for(size_t i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void fillWithRandomNumbers(int* arr, size_t size) {
  for(size_t i = 0; i < size; i++){
    arr[i] = rand();
  }
}
