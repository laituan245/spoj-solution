// SCUBADIV - Scuba diver
// http://www.spoj.com/problems/SCUBADIV/
// laituanksa245

#include <iostream>
using namespace std;

const int INF_WEIGHT = 100000000;

int min (int a, int b) {
  if (a < b) return a;
  return b;
}

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

int main () {
  int t;  // Nb of test cases
  int oxygenRequired, nitrogenRequired;
  int oxygen[1000];
  int nitrogen[1000];
  int weight[1000];
  int dp[1000][22][80];
  int nbCylinders;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> oxygenRequired >> nitrogenRequired >> nbCylinders;
    for (int i = 0; i < nbCylinders; i++)
      cin >> oxygen[i] >> nitrogen[i] >> weight[i];

    // Dynamic Programming
    for (int i = 0; i < nbCylinders; i++)
      for (int j = 0; j <= oxygenRequired; j++)
        for (int k = 0; k <= nitrogenRequired; k++) {
          dp[i][j][k] = INF_WEIGHT;
          if (j == 0 && k == 0)
            dp[i][j][k] = 0;
        }

    for (int j = 0; j <= oxygenRequired; j++)
      for (int k = 0; k <= nitrogenRequired; k++)
        if (j <= oxygen[0] && k <= nitrogen[0] && (j > 0 || k > 0)) {
          dp[0][j][k] = weight[0];
        }

    for (int i = 1; i < nbCylinders; i++)
      for (int j = 0; j <= oxygenRequired; j++)
        for (int k = 0; k <= nitrogenRequired; k++) {
          dp[i][j][k] = dp[i-1][j][k];
          if (j <= oxygen[i] && k <= nitrogen[i])
            dp[i][j][k] = min(dp[i][j][k], weight[i]);
          else
            dp[i][j][k] = min(dp[i][j][k], weight[i] + dp[i-1][max(0,j-oxygen[i])][max(0,k-nitrogen[i])]);
        }

    cout << dp[nbCylinders-1][oxygenRequired][nitrogenRequired] << "\n";
  }
}
