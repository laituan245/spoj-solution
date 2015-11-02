// MAXSUMSQ - Maximum Sum Sequences
// http://www.spoj.com/problems/MAXSUMSQ/

#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
  int t, n;
  int a[100000];
  int dp[100000];
  int anotherDp[100000];
  int finalAns1;
  unsigned long long int finalAns2;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
      scanf ("%d", &a[i]);

    dp[0] = a[0];
    anotherDp[0] = 1;
    for (int i = 1; i < n; i++) {
      if (dp[i-1] + a[i] > a[i]) {
        dp[i] = dp[i-1] + a[i];
        anotherDp[i] = anotherDp[i-1];
      }
      else if (a[i] > dp[i-1] + a[i]){
        dp[i] = a[i];
        anotherDp[i] = 1;
      }
      else {
        dp[i] = a[i];
        anotherDp[i] = anotherDp[i-1] + 1;
      }
    }

    finalAns1 = dp[0];
    for (int i = 1; i < n; i++)
      finalAns1 = max (finalAns1, dp[i]);

    finalAns2 = 0;
    for (int i = 0; i < n; i++)
      if (dp[i] == finalAns1)
        finalAns2 += anotherDp[i];
    printf ("%d %llu\n", finalAns1, finalAns2);
  }
}
