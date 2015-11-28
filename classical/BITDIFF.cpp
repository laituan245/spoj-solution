// BITDIFF - Bit Difference
// http://www.spoj.com/problems/BITDIFF/

#include <iostream>
#include <stdio.h>

using namespace std;

int a[10000];
int n;
int tmp[32];
long long int finalRs;

int main() {
	int t;
	scanf("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < 32; i++) {
			tmp[i] = 0;
			for (int j = 0; j < n; j++)
				if (a[j] & (1 << i))
					tmp[i] ++;
		}
		finalRs = 0;
		for (int i = 0; i < 32; i++) {
			finalRs += (tmp[i] * (n - tmp[i]));
			if (finalRs > 10000007)
				finalRs = finalRs % 10000007;
		}
		finalRs = finalRs * 2;
		if (finalRs > 10000007)
			finalRs = finalRs % 10000007;		
		cout << "Case "<< (z+1) << ": " << finalRs << "\n";
	}
}
