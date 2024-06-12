#include <iostream>
#include <random>

using namespace std;

int main() {
  srand(time(NULL));

  long total = 1000L * 1000 * 1000;
  long incircle = 0;

  // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
  std::mt19937 mt{}; 
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  

  for(int i = 0; i < total; i++) {
    double x = dis(mt); 
    double y = dis(mt); 

    // double x = lcg() / (double)RAND_MAX;
    // double y = lcg() / (double)RAND_MAX;

    if(x * x + y * y <= 1) {
      incircle ++;
    }
  }

  double pi = (double)incircle / total * 4.0;
//   cout << "PI " <<  pi << endl;
  printf("PI: %.10f \n", pi);

  return 0;
}