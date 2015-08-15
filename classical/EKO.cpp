// EKO - Eko
// http://www.spoj.com/problems/EKO/
// laituanksa245

#include <stdio.h>
#include <iostream>
using namespace std;

long long finalRs = 0;
long long n, m;
long long a[1000000];

long long max (long long a, long long b) {
  if (a > b) return a;
  return b;
}

long long min (long long a, long long b) {
  if (a < b) return a;
  return b;
}

bool isPossible (long long bound) {
  long long tempM = m;
  for (long long i = 0; i < n; i++)
    if (a[i] > bound) {
      tempM -= (a[i] - bound);
    if (tempM <= 0)
      return true;
  }
  return tempM <= 0;
}

void binarySearch (long long lowerBound, long long upperBound) {
  bool tempBoolVar;
  if (lowerBound > upperBound) return;
  if (lowerBound == upperBound) {
    tempBoolVar = isPossible(lowerBound);
    if (tempBoolVar)
      finalRs = max(finalRs, lowerBound);
    return;
  }

  long long mid = (lowerBound + upperBound) / 2;
  tempBoolVar = isPossible(mid);
  if (tempBoolVar) {
    finalRs = max(finalRs, mid);
    binarySearch (mid + 1, upperBound);
  }
  else
    binarySearch (lowerBound, mid - 1);
}

int main () {
  long long lowerBound, upperBound;
  scanf ("%ld %ld", &n, &m);
  lowerBound = 1; upperBound = 0;
  for (long long i = 0; i < n; i++) {
    scanf ("%ld", &a[i]);
    upperBound = max(upperBound, a[i]);
  }
  binarySearch(lowerBound, upperBound);
  cout << finalRs << "\n";
}
