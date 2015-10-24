// BTCODE_A - Traversing Grid
// http://www.spoj.com/problems/BTCODE_A/

#include <iostream>
#include <map>
#include <utility>
#include <queue>
using namespace std;

long long int gcd(long long int a, long long int b) {
  long long int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

long long int abs (long long int x) {
  return x < 0 ? -x : x;
}

int main () {
  int t;
  long long int xs, ys, xd, yd;
  long long int gcd1, gcd2;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> xs >> ys >> xd >> yd;
    if ((xs == 0 && ys == 0) && (xd == 0 && yd == 0)) {
      cout << "YES\n";
    }
    else if ((xs == 0 && ys == 0) || (xd == 0 && yd == 0)) {
      cout << "NO\n";
    }
    else {
      gcd1 = gcd(abs(xs), abs(ys));
      gcd2 = gcd(abs(xd), abs(yd));
      if (gcd1 > gcd2)
        cout << "NO\n";
      else if (gcd2 % gcd1 != 0)
        cout << "NO\n";
      else {
        long long int tempInt = gcd2 / gcd1;
        if (!(tempInt & (tempInt-1)))
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
}
