// NNUM - One of the Simpsons symbols
// http://www.spoj.com/problems/NNUM/

#include <iostream>
using namespace std;

int main () {
  int n;
  int rs[9];
  rs[1] = 9; rs[2] = 0; rs[3] = 4; rs[4] = 3; rs[5] = 3;
  rs[6] = 1; rs[7] = 4; rs[8] = 3;
  cin >> n;
  cout << rs[n] << "\n";
}
