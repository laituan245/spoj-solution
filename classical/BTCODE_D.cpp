// BTCODE_D - Maximum Profit
// http://www.spoj.com/problems/BTCODE_D/

#include <iostream>
#include <stdio.h>
#define lli long long int

using namespace std;

lli min (lli a, lli b) {
	return a < b ? a : b;
}

lli max (lli a, lli b) {
	return a > b ? a : b;
}


int main () {
	int t;
	int m, n;
	lli a[100][100];
	lli b[100][100];
	lli c[100][100];
	lli d[100][100];
	lli finalRs;
	lli tempMax;
	
	scanf ("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf ("%d %d", &m, &n);
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> b[i][j];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> c[i][j];
		
		finalRs = 0;
		for (int i = 0; i < m; i++) {
			tempMax = 0;
			for (int j = 0; j < n; j++) 
				tempMax = max(tempMax, min(a[i][j], b[i][j]) * c[i][j]);
			finalRs += tempMax;		
		}
		cout << finalRs << "\n";
			
	}
}
