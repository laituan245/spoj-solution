// BSEARCH1 - Binary search
// http://www.spoj.com/problems/BSEARCH1/

#include <iostream>
#include <stdio.h>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
using namespace std;

int binarySearch (int * array, int left, int right, int key) {
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (array[mid] == key) {
		if (mid == 0 || array[mid - 1] != key)
			return mid;
		return binarySearch (array, left, mid - 1, key);
	}
	if (array[mid] > key)
		return binarySearch(array, left, mid - 1, key);
	return binarySearch(array, mid + 1, right, key);
}

int main () {
	int n, q, k;
	int array[100000];
	scanf ("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf ("%d", &array[i]);
	for (int z = 0; z < q; z++) {
		scanf ("%d", &k);
		printf ("%d\n", binarySearch(array, 0, n-1, k));
	}
}
