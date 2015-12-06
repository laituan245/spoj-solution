// MAXXOR - Find the max XOR value
// http://www.spoj.com/problems/MAXXOR/

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	unsigned int l, r;
	unsigned int finalAns = 0;
	int lDigits[32];
	int rDigits[32];
	cin >> l >> r;
	for (int i = 0; i < 32; i++) {
		lDigits[i] = l & 1;
		l = l >> 1;
		rDigits[i] = r & 1;
		r = r >> 1;
	}

	for (int i = 31; i >= 0; i--) 
		if (lDigits[i] != rDigits[i]) {
			finalAns = (1 << (i + 1)) - 1;
			break;
		}
	cout << finalAns << "\n";
}