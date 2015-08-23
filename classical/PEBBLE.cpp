// PEBBLE - Pebble Solver
// http://www.spoj.com/problems/PEBBLE/
// laituanksa245

#include <iostream>
#include <string>

using namespace std;

int main () {
  string tempStr;
  int finalRs = 0;
  int count = 0;
  int z = 0;
  while (cin >> tempStr) {
    z++;
    finalRs = 0;
    for (int i = 0; i < tempStr.length(); i++)
      if ((tempStr[i] == '1' && finalRs % 2 == 0) || (tempStr[i] == '0' && finalRs % 2 == 1))
        finalRs ++;
    cout << "Game #" << z << ": " << finalRs << "\n";
  }
}
