// AMBM - Ambitious Manager
// http://www.spoj.com/problems/AMBM/

#include <iostream>

#define ulli unsigned long long int

using namespace std;

ulli n;
ulli k;
ulli a[50];
ulli finalRs;
ulli tempOne = 1;

bool binarySearch (ulli lowerBound, ulli upperBound) {
  if (lowerBound > upperBound)
    return false;
  ulli mid = (lowerBound + upperBound) / 2;
  ulli tempMid = mid;
  ulli tempRs = 0;
  for (int i = 0; i < k; i++) {
    tempRs += (tempMid * a[i]);
    tempMid = tempMid >> 1;
    if (tempRs > n)
      break;
  }
  if (tempRs == n) {
    finalRs = mid;
    return true;
  }
  else if (tempRs < n)
    return binarySearch (mid+1, upperBound);
  else
    return binarySearch (lowerBound, mid-1);
}

int main () {
  int t;
  bool foundAns;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> k;
    for (int i = 0; i < k; i++)
      cin >> a[i];
      foundAns = binarySearch(0, (tempOne << k) - 1);
    if (!foundAns)
      cout << -1 << "\n";
    else {
      bool first = true;
      for (int i = 0; i < k; i++) {
        if (finalRs & tempOne) {
          if (first)
            first = false;
          else
            cout << " ";
          cout << (i + 1);
        }
        finalRs = finalRs >> 1;
      }
      cout << "\n";
    }
  }
}
