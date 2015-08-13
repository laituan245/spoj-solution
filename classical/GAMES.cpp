// GAMES - HOW MANY GAMES
// http://www.spoj.com/problems/GAMES/
// laituanksa245

#include <iostream>
#include <math.h>
using namespace std;

double abs (double a) {
  if (a < 0) return -a;
  return a;
}

int gcd (int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main () {
  int t;    // Nb of test cases
  double avg;
  int tempNb1, tempNb2, tempNb3;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> avg;
    avg = abs(avg - floor(avg));
    if (avg == 0)
      cout << "1\n";
    else {
      tempNb1 = 1;
      for (int i = 0; i < 4; i++) {
        avg = avg * 10;
        tempNb1 = tempNb1 * 10;
      }
      tempNb2 = (int) (avg + 0.5);
      tempNb3 = (tempNb1 * tempNb2) / gcd(tempNb1, tempNb2);
      cout << tempNb3 / tempNb2 << "\n";
    }
  }
}
