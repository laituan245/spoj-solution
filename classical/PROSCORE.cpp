// PROSCORE - Problem Set Score
// http://www.spoj.com/problems/PROSCORE/

#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
  int t, n, p; // n is nb of teams, p is nb of problems
  int rs, tmp;
  int teams[10];
  int problems[10];
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> p;
    for (int i = 0; i < n; i++)
      teams[i] = 0;
    for (int j = 0; j < p; j++)
      problems[j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < p; j++) {
        cin >> tmp;
        teams[i] += tmp;
        problems[j] += tmp;
      }
    rs = 7;
    // Check for condition 1
    for (int j = 0; j < p; j++)
      if (problems[j] == 0) {
        rs = rs - 4;
        break;
      }
    // Check for condition 2
    for (int i = 0; i < n; i++)
      if (teams[i] < 1) {
        rs = rs - 2;
        break;
      }
    // Check for condition 3
    for (int i = 0; i < n; i++)
      if (teams[i] >= p) {
        rs = rs - 1;
        break;
      }
    cout << "Case " << (z+1) << ": " << rs << "\n";
  }
}
