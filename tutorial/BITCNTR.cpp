// BITCNTR - Bit counts
// http://www.spoj.com/problems/BITCNTR/

#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int t;
	int n, finalRs;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n;
		finalRs = 0;
		while (n != 0) {
			finalRs ++;
			n = n & (n - 1);
		}
		cout << finalRs << "\n";
	}
}
