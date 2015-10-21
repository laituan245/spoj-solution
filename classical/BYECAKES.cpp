#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
  int t;
  while (b != 0) {
       t = b;
       b = a % b;
       a = t;
  }
  return a;
}

int max (int a, int b) {
  return a > b ? a : b;
}

int max4 (int a, int b, int c, int d) {
  return max(max(a,b), max(c,d));
}

int main () {
  double e, f, s, m;
  double ePrime, fPrime, sPrime, mPrime;
  int tmp1, tmp2, tmp3, tmp4;
  int tmpMax;
  while (true) {
    cin >> e >> f >> s >> m >> ePrime >> fPrime >> sPrime >> mPrime;
    if (e == -1 && f == -1 && s == -1 && m == -1 && ePrime == -1 && fPrime == -1 && sPrime == -1 && mPrime == -1)
      break;
    if (e == 0 && f == 0 && s == 0 && m == 0)
      cout << "0 0 0 0\n";
    else {
      tmp1 = (int) ceil(e / ePrime);
      tmp2 = (int) ceil(f / fPrime);
      tmp3 = (int) ceil(s / sPrime);
      tmp4 = (int) ceil(m / mPrime);
      tmpMax = max4(tmp1, tmp2, tmp3, tmp4);
      cout << (int)(ePrime * tmpMax - e) << " " << (int)(fPrime * tmpMax - f) << " " << (int)(sPrime * tmpMax - s) << " " << (int)(mPrime * tmpMax - m) << "\n";
    }
  }
}
