// NGM - A Game with Numbers
// http://www.spoj.com/problems/NGM/

#include <iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  if (n % 10 == 0) {
    cout << 2 << "\n";
  }
  else {
    cout << 1 << "\n";
    cout << (n % 10) << "\n";
  }
}
