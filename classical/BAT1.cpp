// BAT1 - BATMAN1
// http://www.spoj.com/problems/BAT1/
// laituanksa245

#include <iostream>
using namespace std;

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

int main () {
  int t;
  int n, m, k;
  int finalAns;
  int openingCost[21];
  int cost[21][21];
  int rating[21][21];
  int dp[21][21][1001];
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      cin >> openingCost[i];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> cost[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> rating[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= m; j++)
        for (int h = 0; h <= k; h++) {
          if (j == 0) {
            if (i == 1)
              dp[i][j][h] = 0;
            else {
              dp[i][j][h] = dp[i-1][j][h];
              if (h >= openingCost[i-1])
                dp[i][j][h] = max (dp[i][j][h], dp[i-1][m][h-openingCost[i-1]]);
            }
          }
          else {
            dp[i][j][h] = dp[i][j-1][h];
            int tempIndex = 0;
            while (true) {
              tempIndex++;
              if (h >= tempIndex * cost[i][j])
                dp[i][j][h] = max(dp[i][j][h], tempIndex * rating[i][j] + dp[i][j-1][h-tempIndex * cost[i][j]]);
              else
                break;
            }
          }
        }
    finalAns = 0;
    if (k >= openingCost[n])
      finalAns = max(finalAns, dp[n][m][k-openingCost[n]]);
    finalAns = max(finalAns, dp[n][0][k]);
    cout << finalAns << "\n";
  }
}
