// GRIDSUM1 - 2x2 Subgrid Sum Problem (medium)
// http://www.spoj.com/problems/GRIDSUM1/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <stdio.h>
#include <set>
using namespace std;

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

int a, b, n;
int cells[3][3];
long long int finalRs;

void getSol () {
	int rangeMin, rangeMax, tmpSum; 
	long long int anotherTemp;
	for (int m1 = a; m1 <= b; m1++) 
	for (int m2 = a; m2 <= b; m2++)
	for (int m3 = m1; m3 <= b; m3++) {
		cells[1][0] = m1; cells[1][1] = m2; cells[1][2] = m3;
		
		rangeMin = a; rangeMax = b;
		
		tmpSum = n - (cells[1][0] + cells[1][1]);
		rangeMax = min(rangeMax, tmpSum - a);
		rangeMin = max(rangeMin, tmpSum - b);

		tmpSum = n - (cells[1][1] + cells[1][2]);
		rangeMax = min(rangeMax, tmpSum - a);
		rangeMin = max(rangeMin, tmpSum - b);
		
		if (rangeMin <= rangeMax) {
			anotherTemp = (rangeMax - rangeMin + 1);
			anotherTemp = anotherTemp * anotherTemp;
			finalRs += anotherTemp;
			if (m1 != m3)
				finalRs += anotherTemp;
		}
		
	}

}

int main () {
	int t;
	inp(t);
	for (int z = 0; z < t; z++) {
		inp(a); inp(b); inp(n);
		finalRs = 0;
		getSol();
		cout << finalRs << "\n";
	}
}
