// VECTAR10 - Card Game
// http://www.spoj.com/problems/VECTAR10/

#include <stdio.h>
#include <iostream>
using namespace std;

int dp[1000001][2]; // 0 means throws away the top card first
                    // 1 means moves the card that is now on the top of the deck to the bottom of the deck first
void dynamic_programming() {
  dp[1][0] = 1; dp[2][0] = 2; dp[3][0] = 2;
  dp[1][1] = 1; dp[2][1] = 1; dp[3][1] = 3;
  for (int i = 4; i < 1000001; i++)
    for (int j = 0; j < 2; j++) {
      if (j == 0) {
        if (i % 2 == 0)
          dp[i][j] = dp[i / 2][0] * 2;
        else
          dp[i][j] = dp[i / 2][1] * 2;
      } else if (j == 1) {
        if (i % 2 == 0)
          dp[i][j] = dp[i/2][1] * 2 - 1;
        else
          dp[i][j] = dp[i/2 + 1][0] * 2 - 1;
      }
    }
}

int main() {
  dynamic_programming();
  int n;
  while(true) {
    scanf("%d", &n);
    if (n == 0) break;
    printf("%d\n", dp[n][0]);
  }

}
