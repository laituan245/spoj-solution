// RPLN - Negative Score
// http://www.spoj.com/problems/RPLN/

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

struct Element {
	int left;
	int right;
	int minVal;
};

int n;	// total nb of evaluations
int arr[100001];
Element * tree;

void initialize() {
	int k = 1;
	while (k < n)
		k = k * 2;
	int nbOfNodes = 2 * k - 1;
	for (int i = 1; i <= nbOfNodes; i++) {
		if (i == 1) {
			tree[i].left = 1;
			tree[i].right = n;
		}
		else {
			int parent_left = tree[i/2].left;
			int parent_right = tree[i/2].right;
			if (parent_left == parent_right) {
				tree[i].left = 0;
				tree[i].right = 0;
			}
			else {
				int parent_mid = (parent_left + parent_right) / 2;
				if (i % 2 == 0) {
					tree[i].left = parent_left;
					tree[i].right = parent_mid;
				}
				else {
					tree[i].left = parent_mid + 1;
					tree[i].right = parent_right; 
				}
			}
		}
	}
}

void constructTree (int nodeNb) {
	if (tree[nodeNb].left == tree[nodeNb].right) {
		tree[nodeNb].minVal = arr[tree[nodeNb].left];
		return;
	}
	
	constructTree(nodeNb * 2);
	constructTree(nodeNb * 2 + 1);
	tree[nodeNb].minVal = min(tree[nodeNb * 2].minVal, tree[nodeNb * 2 + 1].minVal);
	return;
}

int getMin (int nodeNb, int left, int right) {
	int cur_left = tree[nodeNb].left;
	int cur_right = tree[nodeNb].right;
	if (cur_left > right || cur_right < left)
		return 2000000000;
	if (left <= cur_left && cur_right <= right)
		return tree[nodeNb].minVal;
	
	return min(getMin(nodeNb*2, left, right), getMin(nodeNb*2 + 1, left, right));
}

int main () {
	int t;
	int nbQuery;
	int tmpA, tmpB;
	
	tree = new Element[262144];
	
	inp(t);
	for (int z = 0; z < t; z++) {
		inp(n); inp(nbQuery);
		for (int i = 1; i <= n; i++) 
			inp(arr[i]);
		
		initialize();
		constructTree(1);
		
		printf ("Scenario #%d:\n", (z+1));		
		for (int q = 0; q < nbQuery; q++) {
			inp(tmpA); inp(tmpB);
			printf ("%d\n", getMin(1, tmpA, tmpB));
		}
	}
	
	delete [] tree;
}
