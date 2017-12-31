// ADACUT - Ada and Alley
// http://www.spoj.com/problems/ADACUT/

#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include<set>
#include<unordered_map>
#define lli long long int
using namespace std;

lli n;
lli height[300000];

inline void inp( lli &n ) {
  n=0;
  lli ch=getchar_unlocked();lli sign=1;
  while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while(ch >= '0' && ch <= '9' )
         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

void Swap(lli &a,lli &b){
	lli temp = a;
	a = b;
	b =  temp;
}

void QuickSort(lli * A, lli Left, lli Right){
	lli i = Left, j = Right;
	lli pivot = A[(Left + Right) / 2];
	/* partition */
	while (i <= j) {
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
	   		j--;
	 	if (i <= j) {
	  		Swap(A[i],A[j]);
	  		i++;
	  		j--;
	 	}
	}

	/* recursion */
	if (Left < j)
		QuickSort(A, Left, j);
	if (i < Right)
		QuickSort(A, i, Right);
}

int main() {
  inp(n);
  for (lli i = 0; i < n; i++) inp(height[i]);
  QuickSort(height, 0, n-1);

  lli sumHeight, curDeduction, maxDeduction;
  sumHeight = 0; maxDeduction = 0;
  for (lli i = 0; i < n; i++) {
    sumHeight += height[i];
    if (i == 0 || height[i] != height[i-1])
      curDeduction = (height[i] * (n-i));
    if (maxDeduction < curDeduction)
      maxDeduction = curDeduction;
  }
  cout << sumHeight - maxDeduction << "\n";
}
