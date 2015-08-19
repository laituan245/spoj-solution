// NFURY - Training Land of Fury
// www.spoj.com/problems/NFURY/
// laituanksa245

#include <stdio.h>
#include <math.h>
using namespace std;

int min (int a, int b) {
  if (a < b) return a;
  return b;
}

int main () {
    int n, t, k;
    int dpAns [1001];
    dpAns[0] = 0; dpAns[1] = 1; dpAns[2] = 2;
    for (int i = 3; i < 1001; i++) {
      k = (int) sqrt(i);
      dpAns[i] = i;
      for (int j = 1; j <= k; j++)
        dpAns[i] = min(dpAns[i], 1 + dpAns[i - j*j]);
    }
    scanf ("%d", &t);
    for (int z = 0; z < t; z++) {
      scanf ("%d", &n);
      printf ("%d\n", dpAns[n]);
    }
}
