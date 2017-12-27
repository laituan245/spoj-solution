// ACMT - Acm Teams
// http://www.spoj.com/problems/ACMT/

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
  int t, e, n, max_team, max_type2_team;
  inp(t); // Nb of test cases
  for (int z = 0; z < t; z++) {
    inp(e); // the number of experienced participants
    inp(n); // the number of newbies
    max_team = 0;
    max_type2_team = e / 2; // Max nb of team consisting of two experienced members plus one newbie
    for (int type2_team = 0; type2_team <= max_type2_team; type2_team++) {
      int remain_e = e - type2_team * 2;
      int remain_n = n - type2_team;
      if (remain_n < 0) break;
      int type1_team = min(remain_e, remain_n / 2);
      if (type1_team + type2_team > max_team)
        max_team = type1_team + type2_team;
    }
    cout << max_team << "\n";
  }
}
