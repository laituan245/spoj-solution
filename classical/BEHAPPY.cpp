// BEHAPPY - Be Awesome As Barney Stinson
// http://www.spoj.com/problems/BEHAPPY/

#include <iostream>
using namespace std;

int main () {
  int n, m;
  int a[20];
  int b[20];
  unsigned long long int dp[20][101];
  while (cin >> m >> n) {
    if (m == 0 && n == 0)
      break;
    for (int i = 0; i < m; i++)
      cin >> a[i] >> b[i];
    for (int i = 0; i < m; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j] = 0;

    for (int j = a[0]; j <= b[0]; j++)
      dp[0][j] = 1;

    for (int i = 1; i < m; i++)
      for (int j = 0; j <= n; j++) {
        dp[i][j] = 0;
        for (int z = a[i]; z <= b[i]; z++)
          if (j - z >= 0)
            dp[i][j] += dp[i-1][j-z];
      }

    cout << dp[m-1][n] << "\n";
  }
}
