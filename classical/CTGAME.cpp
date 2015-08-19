// CTGAME - City Game
// www.spoj.com/problems/CTGAME/
// laituanksa245

#include <iostream>
using namespace std;

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

int main () {
  int t;      // Nb of datasets
  int n, m, tempInt;
  char city[1001][1001];
  int dpArea[1001][1001];
  short prev[1001][1001];
  cin >> t;
  for (int z = 0; z < t; z++){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> city[i][j];
        dpArea[i][j] = 0;
      }
    }

    // This step takes O(n * m)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (city[i][j] == 'R')
          prev[i][j] = -1;
        else {
          if (j == 0 || prev[i][j-1] == -1)
            prev[i][j] = j;
          else
            prev[i][j] = prev[i][j-1];
        }
    }

    // This step takes
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (city[i][j] == 'R')
          dpArea[i][j] = -1;
        else {
          dpArea[i][j] = 1;
          tempInt = -1;
          for (int z = i; z >= 0; z--)
            if (city[z][j] == 'R')
              break;
            else {
              if (tempInt == -1 || tempInt < prev[z][j])
                tempInt = prev[z][j];
              dpArea[i][j] = max(dpArea[i][j], (i-z+1) * (j-tempInt+1));
            }
        }

    int finalAns = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        finalAns = max(finalAns, dpArea[i][j]);
    cout << (3*finalAns) << "\n";
  }
}
