// RMID2 - Running Median Again
// http://www.spoj.com/problems/RMID2/

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
  int t; // Nb of test cases;
  int n, temp;
  int nb1, nb2;
  inp(t);
  for (int z = 0; z < t; z++) {
    priority_queue <int> maxHeap;
    priority_queue < int, vector <int>, greater <int> > minHeap;
    while (true) {
      inp (n);

      if (n == 0)
        break;
      else if (n == -1) {
        printf ("%d\n", maxHeap.top ());
        maxHeap.pop ();
        if (maxHeap.size() < minHeap.size()) {
          temp = minHeap.top ();
          minHeap.pop ();
          maxHeap.push (temp);
        }
      }
      else {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
          maxHeap.push (n);
        else {
          nb1 = maxHeap.top ();
          if (n >= nb1)
            minHeap.push (n);
          else
            maxHeap.push (n);

          if (maxHeap.size() < minHeap.size()) {
            temp = minHeap.top ();
            minHeap.pop ();
            maxHeap.push (temp);
          }
          else if (maxHeap.size() > minHeap.size() + 1) {
            temp = maxHeap.top ();
            maxHeap.pop ();
            minHeap.push (temp);
          }
        }
      }
    }
  }
}
