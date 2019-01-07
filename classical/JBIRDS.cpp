// JBIRDS
// https://www.spoj.com/problems/JBIRDS/

#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include<set>
#include<unordered_map>
#include<math.h>
using namespace std;

bool dp[10000][100001];

inline void inp( int &n ) {
  n=0;
  int ch=getchar_unlocked();int sign=1;
  while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while(ch >= '0' && ch <= '9' )
         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

int main() {
    int n, half_sum, total_sum = 0;
    int a[10000];
    inp(n);
    for (int i = 0; i < n; i++) {
        inp(a[i]);
        total_sum += a[i];
    }
    half_sum = total_sum / 2;

    // Dynamic Programming
    for (int j = 0; j <= half_sum; j++) dp[0][j] = false;
    dp[0][0] = true;
    dp[0][a[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= half_sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i] && dp[i-1][j-a[i]]) dp[i][j] = true;
        }
    }

    int final_result = total_sum;
    for (int i = 0; i <= half_sum; i++)
        if (dp[n-1][i])
            final_result = min(final_result, total_sum-2*i);
    cout << final_result << "\n";
}
