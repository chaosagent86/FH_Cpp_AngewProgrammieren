#include <iostream>
#include <cmath>
#include <map>

using namespace std;

long lcgSeed = 0;

long lcg() {
  long a = 1103515245;
  long m = 2147483648; //pow(2, 31);
  long c = 12345;

  lcgSeed = (a * lcgSeed + c) % m;
  return lcgSeed;
}

int main() {
  lcgSeed = time(NULL); // SEED
  srand(lcgSeed);

  long total = 1000L * 1000;
  long incircle = 0;

  for(int i = 0; i < total; i++) {
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;

    // double x = lcg() / (double)RAND_MAX;
    // double y = lcg() / (double)RAND_MAX;

    if(x * x + y * y <= 1) {
      incircle ++;
    }
  }

  double pi = (double)incircle / total * 4.0;
  //cout << "PI " <<  pi << endl;
  printf("PI: %.10f \n", pi);

  return 0;
}