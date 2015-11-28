// VISIBLEBOX - Decreasing Number of Visible Box
// http://www.spoj.com/problems/VISIBLEBOX/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n;
int a[150000];
int tmpArr[150000];
int tail, head;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main () {
	int t;
	scanf ("%d", &t);
	for (int z = 0; z < t; z++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
			
		qsort(a, n, sizeof(int), compare);
		
		tail = 0;
		head = 0;
		tmpArr[head] = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] >= 2 * tmpArr[head]) {
				head = head + 1;
				tail = tail + 1;
				tmpArr[tail] = a[i];
			}
			else {
				tail = tail + 1;
				tmpArr[tail] = a[i];
			}
		}
		
		cout << "Case " << (z+1) << ": " << (tail-head+1) << "\n";
	}	
}
