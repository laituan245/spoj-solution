// BDOI16D - One Punch Man
// http://www.spoj.com/problems/BDOI16D/

#include <iostream>
#include <stdio.h>
using namespace std;

int x[100000];
int v[100000];
int backward_idx[100000];
int dp[100001][51];
int cumulative_sum[100000];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int abs(int a) {
	return a > 0 ? a : -a;
}

int max (int a, int b) {
	return a > b ? a : b;
}

bool with_in_range(int x1, int x2, int r) {
	return (abs(x1-x2) <= 2 * r);
}

void quickSort(int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = x[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (x[i] < pivot)
                  i++;
            while (x[j] > pivot)
                  j--;
            if (i <= j) {
                  swap(x[i], x[j]);
                  swap(v[i], v[j]);
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(left, j);
      if (i < right)
            quickSort(i, right);
}


int main() {
	int t, n, r, k, start_idx, end_idx;
	scanf("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf("%d %d %d", &n, &r, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &v[i]);
			backward_idx[i] = i;
		}
		quickSort(0, n-1);
		for (int i = 0; i < n; i++) {
			if (i == 0)
				cumulative_sum[i] = v[i];
			else
				cumulative_sum[i] = v[i] + cumulative_sum[i-1];
		}
		start_idx = 0; end_idx = 0;
		while (start_idx < n) {
			while (end_idx < n && with_in_range(x[start_idx], x[end_idx], r)) {
				backward_idx[end_idx] = start_idx;
				end_idx ++;
			}
			start_idx++;
		}

		// Dynamic Programming
		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;
		for (int j = 0; j <= k; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = dp[i-1][j];
				if (backward_idx[i-1] == 0)
					dp[i][j] = max(dp[i][j], cumulative_sum[i-1]);
				else {
					dp[i][j] = max(dp[i][j], dp[backward_idx[i-1]][j-1] + cumulative_sum[i-1]-cumulative_sum[backward_idx[i-1]-1]);
				}
			}
		}

		cout << "Case " << (z+1) << ": " << dp[n][k] << "\n";
	}
}