// RPLC - Coke madness
// http://www.spoj.com/problems/RPLC/
// laituanksa245

#include <stdio.h>
#include <iostream>
using namespace std;

long long min (long long a, long long b) {
  if (a < b) return a;
  return b;
}

int main () {
  int t;  // Nb of test cases
  int n, tempNb;
  long long rs = 0;
  long long tempSum = 0;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {
    rs = 0;
    tempSum = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf ("%d", &tempNb);
      tempSum += tempNb;
      rs = min (tempSum, rs);
    }
    if (rs == 0)
      rs = 1;
    if (rs < 0)
      rs = (-rs) + 1;
    cout << "Scenario #" <<  (z+1) << ": " << rs << "\n";
  }
}
