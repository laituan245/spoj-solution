// SUMFOUR - 4 values whose sum is 0
// http://www.spoj.com/problems/SUMFOUR/

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
#include <unordered_map>
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


int main () {
  int n;
  int a[4000], b[4000], c[4000], d[4000];
  int finalRs = 0;
  int tempSum;
  int tempIndex1, tempIndex2;
  unordered_map <int, int> myMap;
  myMap.reserve(16000000);
  inp(n);
  for (int i = 0; i < n; i++) {
    inp (a[i]); inp (b[i]); inp (c[i]); inp (d[i]);
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      myMap[c[i] + d[j]] ++;


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      tempSum = -(a[i] + b[j]);
      if (myMap.find(tempSum) != myMap.end())
        finalRs += myMap[tempSum];
    }

  cout << finalRs << "\n";
}
