// ASHMHF - Meet Her Fast!
// https://www.spoj.com/problems/ASHMHF/
// Code is not very clean.

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
#define lli long long int
using namespace std;

int n; // Number of hotels
int locations[100000]; // Hotel Locations
int indexes[100000];   // Hotel Indexes

inline void inp( int &n ) {
  n=0;
  int ch=getchar_unlocked();int sign=1;
  while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while(ch >= '0' && ch <= '9' )
         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

void swap (int index_i, int index_j) {
    // Swapping the location
    int tmp = locations[index_i];
	locations[index_i] = locations[index_j];
	locations[index_j] = tmp;
    // Swapping the indexes
    tmp = indexes[index_i];
    indexes[index_i] = indexes[index_j];
    indexes[index_j] = tmp;
}

void quickSort (int left, int right) {
	if (left >= right) return;
	int pivotVal = locations[left];
	int tmpIndex = left + 1;
	for (int i = left + 1; i <= right; i++)
		if (locations[i] <= pivotVal) {
			swap(i, tmpIndex);
			tmpIndex ++;
		}

	swap (left, tmpIndex-1);
	quickSort (left, tmpIndex-2);
	quickSort (tmpIndex, right);
}

int main() {
    int t; // Number of test cases
    inp (t);
    for (int case_nb = 1; case_nb <= t; case_nb++) {
        inp(n);
        for (int i = 0; i < n; i++) {
            inp(locations[i]);
            indexes[i] = i + 1;
        }

        if (n == 1)
            cout << "Case " << case_nb << ": 1\n";
        else {
            quickSort(0, n-1);
            int final_answer = 0;

            lli delta = 0;
            for (int i = 1; i < n; i++) {
                delta += (locations[i] - locations[i-1]) * (2 * i - n);
                if (delta < 0 || (delta == 0 && indexes[i] < indexes[final_answer])) {
                    final_answer = i;
                    delta = 0;
                }
            }

            cout << "Case " << case_nb << ": " << indexes[final_answer] << "\n";
        }
    }
}
