// LASTDIG2 - The last digit re-visited
// http://www.spoj.com/problems/LASTDIG2/
#include <iostream>
#include <string>
#define ulli unsigned long long int
using namespace std;

int cTd (char c) {
  string s = "0123456789";
  for (int i = 0; i < s.length(); i++)
    if (s[i] == c) return i;
}
int main () {
  int t,lD,fRs,rmd;
  string a; ulli b;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> a >> b;
    if (b == 0) cout << "1\n";
    else {
      lD = cTd(a[a.length()-1]);
      rmd = b % 4; if (!rmd) rmd = 4;fRs = 1;
      for (int i = 0; i < rmd; i++)
        fRs *= lD;
      cout << (fRs % 10) << "\n";
    }
  }
}
