// ADABANKET - Ada and Banquet
// http://www.spoj.com/problems/ADABANKET/

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
using namespace std;

inline void inp( int &n ) {
  n=0;
  int ch=getchar_unlocked();int sign=1;
  while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while(ch >= '0' && ch <= '9' )
         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

int main() {
  int n, tmp, min_count, count;
  inp(n); // Number of friends
  min_count = -1;
  for(int i = 0; i < n; i++) {
    count = 0;
    for (int j = 0; j < n; j++) {
      inp(tmp);
      count += tmp;
    }
    if (min_count < 0 or min_count > count) min_count = count;
  }
  cout << (2 * min_count) << "\n";
}
