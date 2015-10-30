// GIRLSNBS - Girls and Boys
// http://www.spoj.com/problems/GIRLSNBS/

#include <iostream>
using namespace std;

int max (int a, int b) {
  return a > b ? a : b;
}

int min (int a, int b) {
  return a < b ? a : b;
}

int main () {
  int g, b;
  int nb1, nb2;
  int finalRs;
  while (cin >> g >> b) {
    if (g == -1 && b == -1)
      break;
    nb1 = min(g,b);
    nb2 = max(g,b);
    if (nb1 != 0) {
      finalRs = nb2 / (nb1+1);
      if (nb2 % (nb1 + 1) != 0)
        finalRs++;
    }
    else
      finalRs = nb2;

    cout << finalRs << "\n";
  }
}
