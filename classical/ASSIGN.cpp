// ASSIGN - Assignments
// http://www.spoj.com/problems/ASSIGN/

#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int nbOfOneBits (int nb) {
  if (nb == 0)
    return 0;
  int finalRs = 0;
  while (nb) {
    finalRs ++;
    nb = nb & (nb - 1);
  }
  return finalRs;
}

int main () {
  int t, n, nbPeople;
  int tempInt;
  int preferences[20][20];
  unordered_map <int, long long int> dp;
  cin >> t;

  for (int z = 0; z < t; z++) {
    dp.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> preferences[i][j];   // if preferences[i][j] = 1 then student (i+1)-th likes the (j+1)-th topi
    tempInt = 1 << n;
    dp[0] = 1;
    for (int i = 1; i < tempInt; i++) {
      dp[i] = 0;
      nbPeople = nbOfOneBits(i);
      for (int j = 0; j < n; j++)
        if (preferences[nbPeople-1][j] && (i & (1 << j))) {
          dp[i] += dp[i & ~(1 << j)];
        }
    }
    cout << dp[tempInt-1] << "\n";
  }
}
