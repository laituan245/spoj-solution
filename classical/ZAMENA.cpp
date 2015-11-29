// ZAMENA - Zamena
// www.spoj.com/problems/ZAMENA/

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

int n;
int id[100000];
int dp[100000];
int finalRs;
unordered_map <int, int> myMap;

int main () {
  int tmpInt, nbDigits;
  int digits[10];

  inp(n);
  for (int i = 0; i < n; i++)
    inp(id[i]);
  if (id[0] == 0) {
    cout << "0\n";
    return 0;
  }
  dp[0] = 0;
  myMap[id[0]] = 0;

  for (int i = 1; i < n; i++) {
    tmpInt = id[i];
    nbDigits = 0;
    while (tmpInt > 0) {
      digits[nbDigits] = tmpInt % 10;
      tmpInt = tmpInt / 10;
      nbDigits ++;
    }
    dp[i] = 0;
    for (int j = 0; j < nbDigits; j++) {
      for (int z = 0; z < 10; z++)
        if (z != digits[j]) {
          tmpInt = 0;
          for (int h = nbDigits - 1; h >= 0; h--)
            if (h != j)
              tmpInt = tmpInt * 10 + digits[h];
            else
              tmpInt = tmpInt * 10 + z;
          if (myMap.find(tmpInt) != myMap.end())
            dp[i] = max(dp[i], dp[myMap[tmpInt]] + abs(digits[j] - z));

        }
    }
    myMap[id[i]] = i;
  }

  finalRs = 0;
  for (int i = 0; i < n; i++)
    finalRs = max(finalRs, dp[i]);
  cout << finalRs << "\n";
}
