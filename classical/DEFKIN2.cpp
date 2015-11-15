// DEFKIN2 - Defense of a kingdom 2
// http://www.spoj.com/problems/DEFKIN2/

#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int t;
	int w, h, n;
	int tempX, tempY, finalRs;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> w >> h >> n;
		if (n >= min(w,h))
			cout << 0 << "\n";
		else if (n == 0)
			cout << w * h << "\n";
		else {
			w = w - n;
			h = h - n;
			tempX = w / (n+1);
			if (w % (n+1))
				tempX ++;
			tempY = h / (n+1);
			if (h % (n+1))
				tempY ++;
			finalRs = tempX * tempY;
			cout << finalRs << "\n";
		}
	}
}
