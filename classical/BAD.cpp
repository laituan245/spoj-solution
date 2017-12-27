// BAD - Badminton Tournament - Easy
// http://www.spoj.com/problems/BAD/

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
  int t, n, a, b, nb_matches;
  int q, max_count;
  bool defeated[251][251];
  bool isInList[251][251];
  int count[251];
  inp(t); // Nb of test cases
  for (int z = 0; z < t; z++) {
    inp(n);

    // Initialization
    for (int i = 1; i <= n; i++) count[i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        defeated[i][j] = false;
        isInList[i][j] = false;
      }

    // Input the results of matches
    nb_matches = n * (n-1) / 2;
    for (int i = 0; i < nb_matches; i++) {
      inp(a); inp(b); // a defeated b
      defeated[a][b] = true;
      if (!isInList[a][b]) count[a]++;
      isInList[a][b] = true;
    }

    // Consider every triples
    for (int i = 1; i <= n; i++)
      for (int j = i+1; j <= n; j++)
        for (int k = j+1; k <= n; k++) {
          // Case 1
          if (defeated[i][j] and defeated[j][k]) {
            if (!isInList[i][k]) count[i]++;
            isInList[i][k] = true;
          }
          // Case 2
          if (defeated[k][j] and defeated[j][i]) {
            if (!isInList[k][i]) count[k]++;
            isInList[k][i] = true;
          }
          // Case 3
          if (defeated[k][i] and defeated[i][j]) {
            if (!isInList[k][j]) count[k]++;
            isInList[k][j] = true;
          }

          // Case 4
          if (defeated[j][i] and defeated[i][k]) {
            if (!isInList[j][k]) count[j]++;
            isInList[j][k] = true;
          }

          // Case 5
          if (defeated[i][k] and defeated[k][j]) {
            if (!isInList[i][j]) count[i]++;
            isInList[i][j] = true;
          }

          // Case 6
          if (defeated[j][k] and defeated[k][i]) {
            if (!isInList[j][i]) count[j]++;
            isInList[j][i] = true;
          }
        }

    max_count = count[1];
    q = 1;
    for (int i = 2; i <= n; i++)
      if (count[i] > max_count){
        max_count = count[i];
        q = i;
      }
    cout << q << " " << max_count << "\n";
  }
}
