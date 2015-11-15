// ACPC11B - Between the Mountains
// http://www.spoj.com/problems/ACPC11B/

#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include <set>
using namespace std;

int abs (int x) {
	return x < 0 ? -x : x;
}

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

void swap (int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quickSort (int * array, int left, int right) {
	if (left >= right) return;
	int pivotVal = array[left];
	int tmpIndex = left + 1;
	for (int i = left + 1; i <= right; i++)
		if (array[i] <= pivotVal) {
			swap (array[i], array[tmpIndex]);
			tmpIndex ++;
		}
		
	swap (array[left], array[tmpIndex-1]);
	quickSort (array, left, tmpIndex-2);
	quickSort (array, tmpIndex, right);
}

int n1, n2;
int a[1000];
int b[1000];

int binarySearch(int key) {
	int left = 0;
	int right = n2-1;
	if (key >= b[right]) return abs(key-b[right]);
	if (key < b[left]) return abs(key-b[left]);
	while (left <= right) {
		int mid = (left + right) / 2;
		if ((left + right) & 1)
			mid = mid + 1;
		if (b[right] <= key) break;
		if (b[mid] == key) return 0;
		if (b[mid] <= key)
			left = mid;
		else if (b[mid] > key)
			right = mid - 1;
	}
	return min(abs(key-b[right]), abs(key-b[right+1]));
}

int main () {
	int t;
	int finalRs;
	inp(t);
	for (int z = 0; z < t; z++) {
		inp(n1);
		for (int i = 0; i < n1; i++)
			inp(a[i]);
		inp(n2);
		for (int i = 0; i < n2; i++)
			inp(b[i]);
		quickSort (b, 0, n2 - 1);
		finalRs = abs(a[0]-b[0]);
		for (int i = 0; i < n1; i++)
			finalRs = min(finalRs, binarySearch(a[i]));
		cout << finalRs << "\n";
	}
}
