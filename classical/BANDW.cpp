// BANDW - Black and White
// http://www.spoj.com/problems/BANDW/

#include <iostream>
#include <string>
using namespace std;

int main () {
  string S, T;
  int finalRs = 0;
  bool inSamePart;
  while (cin >> S >> T) {
    if (S == "*" && T == "*")
      break;
    finalRs = 0;
    inSamePart = true;
    for (int i = 0; i < S.length(); i++) {
      if (!inSamePart && S[i] == T[i])
        inSamePart = true;
      else if (inSamePart && S[i] != T[i]) {
        inSamePart = false;
        finalRs ++;
      }
    }
    cout << finalRs << "\n";
  }
}
