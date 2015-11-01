// UPDATEIT - Update the array !
// http://www.spoj.com/problems/UPDATEIT/

#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include <set>
using namespace std;

struct myElement {
  int v;
  int sum;
  int left;
  int right;
};

int n, nbOfNodes = (1 << 15) - 1;
myElement * arr;

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}


void initialize() {
  arr = new myElement[nbOfNodes + 1];
  for (int i = 1; i <= nbOfNodes; i++) {
    if (i == 1) {
      arr[i].left = 0;
      arr[i].right = n-1;
    }
    else {
      int parent_left = arr[i/2].left;
      int parent_right = arr[i/2].right;
      if (parent_left != parent_right) {
        if (i & 1) {
          arr[i].left = 1 + (parent_left + parent_right) / 2;
          arr[i].right = parent_right;
        }
        else {
          arr[i].left = parent_left;
          arr[i].right = (parent_left + parent_right) / 2;
        }
      }
    }
  }
}

int getResult (int nodeNb, int right) {
  int left = right;
  int curLeft = arr[nodeNb].left;
  int curRight = arr[nodeNb].right;
  int curMiddle = (curLeft + curRight) / 2;
  if (curLeft > right || curRight < left) return 0;
  if (left <= curLeft && curRight <= right)
    return arr[nodeNb].sum + (curRight - curLeft + 1) * arr[nodeNb].v;

  if (curLeft != curRight) {
    arr[nodeNb * 2].v += arr[nodeNb].v;
    arr[nodeNb * 2 + 1].v += arr[nodeNb].v;
    arr[nodeNb].sum += ((curRight - curLeft + 1) * arr[nodeNb].v);
    arr[nodeNb].v = 0;
    if (left <= curMiddle)
      return getResult(nodeNb * 2, right);
    else
      return getResult(1 + nodeNb * 2, right);
  }

}

void update (int nodeNb, int left, int right, int val) {
  int curLeft = arr[nodeNb].left;
  int curRight = arr[nodeNb].right;
  int curMiddle = (curLeft + curRight) / 2;
  if (curLeft > right || curRight < left) return;
  if (left <= curLeft && curRight <= right) {
    arr[nodeNb].v += val;
    return;
  }

  if (curLeft != curRight) {
    arr[nodeNb].sum += (val * (min(right,curRight) - max(left,curLeft) + 1));
    update (nodeNb * 2, left, right, val);
    update (nodeNb * 2 + 1, left, right, val);
  }
}


int main () {
  int t, u, tmpL, tmpR, tmpVal, nbQuery, tempIndex;
  inp (t);
  for (int z = 0; z < t; z++) {
    inp(n);
    inp(u);
    initialize();
    for (int i = 0; i < u; i++) {
      inp(tmpL);
      inp(tmpR);
      inp(tmpVal);
      update (1, tmpL, tmpR, tmpVal);
    }
    inp(nbQuery);
    for (int i = 0; i < nbQuery; i++) {
      inp(tempIndex);
      printf ("%d\n", getResult(1, tempIndex));
    }
  }
  delete [] arr;
}
