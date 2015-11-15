// BITSHUFFLING - Bit Shuffling
// http://www.spoj.com/problems/BITSHUFFLING/

#include <iostream>
#include <stdio.h>
using namespace std;

unsigned int max (unsigned int a, unsigned int b) {
	return a > b ? a : b;
}

unsigned int min (unsigned int a, unsigned int b) {
	return a < b ? a : b;
}

int main () {
	unsigned int n;
	unsigned int maxRs, minRs;
	int k;
	int tmpA, tmpB;
	int bitA, bitB;
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		maxRs = n; minRs = n;
		for (int z = 0; z < k; z++) {
			cin >> tmpA >> tmpB;
			bitA = 0;
			if (n & (1 << tmpA))
				bitA = 1;
			bitB = 0;
			if (n & (1 << tmpB))
				bitB = 1;
			
			if (bitA != bitB) {
				n = n ^ (1 << tmpA); 
				n = n ^ (1 << tmpB);
			}
			maxRs = max(n, maxRs);
			minRs = min(n, minRs);
		}
		cout << n << " " << maxRs << " " << minRs << "\n";
	}
}
