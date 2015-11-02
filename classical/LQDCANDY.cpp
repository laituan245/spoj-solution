// LQDCANDY - CANDY
// http://www.spoj.com/problems/LQDCANDY/

#include <iostream>
#define lli long long int
using namespace std;

bool isPowerOf2 (lli n) {
  return (n > 0) && (!(n & (n-1)));
}

int main () {
  int t;
  lli n;
  lli rsLength, tempRatio, rsTimes;
  lli tempOne = 1;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n;
    if (isPowerOf2(n))
      cout << n << " " << 0 << "\n";
    else {
      rsLength = 1;
      while (rsLength < n) {
        rsLength = rsLength << 1;
      }
      tempRatio = rsLength / (n & (-n));
      for (int i = 0; i <= 61; i++)
        if ((tempOne << i) & tempRatio) {
          rsTimes = i;
          break;
        }
      cout << rsLength << " " << rsTimes << "\n";
    }
  }
}
