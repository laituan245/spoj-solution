// GNYR09F - Adjacent Bit Counts
// http://www.spoj.com/problems/GNYR09F/
// laituanksa245

#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
  int p;
  int datasetNb, n, k;
  long long dp[101][101][2];
  scanf ("%d", &p);
  for (int z = 0; z < p; z++) {
    scanf ("%d %d %d", &datasetNb, &n, &k);
    if (k > n) cout << datasetNb << " 0\n";
    else {
      for (int j = 0; j <= k; j++)
        for (int k = 0; k < 2; k++)
          dp[1][j][k] = 0;
      dp[1][0][0] = 1; dp[1][0][1] = 1;

      for (int i = 2; i <= n; i++)
        for (int j = 0; j <= k; j++)
          for (int k = 0; k < 2; k++) {
            if (k == 0)
              dp[i][j][k] = dp[i-1][j][0] + dp[i-1][j][1];
            else
              dp[i][j][k] = dp[i-1][j][0];

            if (j > 0 && k == 1)
              dp[i][j][k] += dp[i-1][j-1][1];
          }

      cout << datasetNb << " " << (dp[n][k][0] + dp[n][k][1])<< "\n";
    }
  }
}
