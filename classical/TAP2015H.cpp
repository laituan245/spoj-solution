// TAP2015H - Hugo s homework
// http://www.spoj.com/problems/TAP2015H/

#include <iostream>
#include <stdio.h>
using namespace std;

int swap (int &a, int &b) {
  int tg = a;
  a = b;
  b = tg;
}

int main () {
  int n, tmpInt, anotherTmp, finalRs, nbDigits = 0;
  int digits[10];

  while (cin >> n) {
    finalRs = 0;

    while (n != 0) {
      finalRs++;
      tmpInt = n;
      nbDigits = 0;
      while (tmpInt > 0) {
        digits[nbDigits] = tmpInt % 10;
        tmpInt = tmpInt / 10;
        nbDigits ++;
      }

      for (int i = 0; i < nbDigits; i++)
        for (int j = i + 1; j < nbDigits; j++)
          if (digits[i] > digits[j])
            swap(digits[i], digits[j]);

      anotherTmp = 0;
      for (int i = 0; i < nbDigits; i++)
        anotherTmp = anotherTmp * 10 + digits[i];

      n = n - anotherTmp;
    }
    cout << finalRs << "\n";
  }
}
