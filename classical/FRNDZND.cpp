// FRNDZND - Friend Zoned
// http://www.spoj.com/problems/FRNDZND/

#include <iostream>
#include <stdio.h>
using namespace std;

int n, q, l, r;
int arr[100001];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int z = 0; z < q; z++) {
		scanf("%d %d", &l, &r);
		if (l == r)
			cout << arr[l] << "\n";
		else
			cout << 0 << "\n";
	}

}