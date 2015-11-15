// OLOLO - Onotole needs your help
// http://www.spoj.com/problems/OLOLO/
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


int main () {
  int n, temp;
  int rs = 0;
  inp (n);
  for (int i = 0; i < n; i++) {
    inp (temp);
    rs = rs ^ temp;
  }
  cout << rs << "\n";
}
