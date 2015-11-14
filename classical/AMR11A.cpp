// AMR11A - Magic Grid
// http://www.spoj.com/problems/AMR11A/

#include <iostream>
#include <stdio.h>
using namespace std;

int r, c;
int s[501][501];
int dp[501][501];
int finalRs = 300000000;

int absoluteVal (int a) {
	return a < 0 ? -a : a;
}

bool isPossible (int val) {
	s[1][1] = val;
	dp[1][1] = val;
	for (int j = 2; j <= c; j++) {
		dp[1][j] = dp[1][j-1] + s[1][j];
		if (dp[1][j] <= 0)
			dp[1][j] = -300000000;
	}
	
	for (int i = 2; i <= r; i++) {
		dp[i][1] = dp[i-1][1] + s[i][1];
		if (dp[i][1] <= 0)
			dp[i][1] = -300000000;		
	}
	
	for (int i = 2; i <= r; i++)
		for (int j = 2; j <= c; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + s[i][j];
			if (dp[i][j] <= 0)
				dp[i][j] = -300000000;	
		}
		
	return dp[r][c] > 0;
}

void binarySearch (int left, int right) {
	if (left > right) return;
	int mid = (left + right) / 2;
	if (isPossible(mid)) {
		finalRs = min(finalRs, mid);
		binarySearch (left, mid - 1);
	}
	else 
		binarySearch (mid + 1, right);
}

int main () {
	int t;
	int tmpSum;
	scanf ("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf ("%d %d", &r, &c);
		tmpSum = 0;
		finalRs = 300000000;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				scanf ("%d", &s[i][j]);
				tmpSum += absoluteVal(s[i][j]);
			}
		
		binarySearch (1, tmpSum);
		cout << finalRs << "\n";
	}
}
