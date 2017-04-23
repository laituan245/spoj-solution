// QUE1 - Queue (Rookie)
// http://www.spoj.com/problems/QUE1/

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

inline void inp( int &n ) {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int n;
int height[1000];
int nbhigher[1000];

void quickSort(int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = height[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (height[i] < pivot)
              i++;
        while (height[j] > pivot)
              j--;
        if (i <= j) {
              tmp = height[i];
              height[i] = height[j];
              height[j] = tmp;
              tmp = nbhigher[i];
              nbhigher[i] = nbhigher[j];
              nbhigher[j] = tmp;
              i++;
              j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}

void findAns(vector<int> * rs, int left, int right) {
    (* rs).clear();
    if (left == right) {
        (* rs).push_back(height[left]);
    } else {
        bool inserted = false;
        vector <int> tmp_rs; tmp_rs.clear();
        findAns(&tmp_rs, left+1, right);
        for (int i = 0; i < tmp_rs.size(); i++) {
            if (tmp_rs.size()-i == nbhigher[left]) {
                (*rs).push_back(height[left]);
                inserted = true;
            }
            (*rs).push_back(tmp_rs[i]);
        }
        if (!inserted)
            (*rs).push_back(height[left]);
    }
}

int main() {
    int t;
    vector <int> ans;
    inp(t);
    for (int zzz = 0; zzz < t; zzz++) {
        inp(n);
        for (int i = 0; i < n; i++)
            inp(height[i]);
        for (int i = 0; i < n; i++)
            inp(nbhigher[i]);
        quickSort(0, n-1);
        findAns(&ans, 0, n-1);
        for (int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i];
            if (i != 0)
                cout << " ";
        }
        cout << "\n";
    }
}
