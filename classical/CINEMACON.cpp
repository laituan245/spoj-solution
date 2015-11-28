// CINEMACON - Cinema Conundrum
// http://www.spoj.com/problems/CINEMACON/

#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int movieLength[10001];
int tmpSum[10001];
int finalRs;

void binarySearch(int left, int right) {
	if (left > right) return;
	int mid = (left + right) / 2;
	bool isPossible = false;
	
	for (int i = 1; i <= n; i++) {
		int j = i + mid - 1;
		if (j > n)
			break;
		if (tmpSum[j] - tmpSum[i-1] >= m) {
			isPossible = true;
			break;
		}
	}
	
	if (!isPossible)
		binarySearch(mid+1, right);
	else {
		finalRs = min(finalRs, mid);
		if (left < mid)
			binarySearch(left, mid);
	}
}

int main () {
	int t;
	scanf ("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf("%d %d", &n, &m);		
		tmpSum[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &movieLength[i]);
			tmpSum[i] = tmpSum[i-1] + movieLength[i];
		}
		if (m == 0)
			cout << "Case " << (z+1) << ": 0\n";
		else {
			if (tmpSum[n] < m) 
				cout << "Case " << (z+1) << ": -1\n";
			else {
				finalRs = n;
				binarySearch(1, n);
				cout << "Case " << (z+1) << ": " << finalRs << "\n";
			}
		}
	}
}
