// http://www.spoj.com/problems/HORRIBLE/
// HORRIBLE - Horrible Queries
// Segment tree can be used for this problem

#include <iostream>
#include <stdio.h>

#define ulli unsigned long long int
using namespace std;

struct myElement {
  ulli left;
  ulli right;
  ulli sum;
  ulli v;
};

ulli nbNodes, n;
myElement * array;

void initialization () {
  // Initialization
  ulli parent_left, parent_right;
  ulli k = 1;
  while (k < n)
    k = k * 2;
  nbNodes = 2*k-1;
  array = new myElement[nbNodes+1];
  for (ulli i = 1; i <= nbNodes; i++) {
    array[i].sum = 0;
    array[i].v = 0;
    if (i == 1) {
      array[i].left = 1;
      array[i].right = n;
    }
    else {
      parent_left = array[i/2].left;
      parent_right = array[i/2].right;
      if (parent_left != parent_right) {
        if (i & 1) {
          array[i].left = 1 + (parent_left + parent_right)/2;
          array[i].right = parent_right;
        }
        else {
          array[i].left = parent_left;
          array[i].right = (parent_left + parent_right)/2;
        }
      }
    }
  }
}

ulli min (ulli a, ulli b) {
  return a < b ? a : b;
}


ulli max (ulli a, ulli b) {
  return a > b ? a : b;
}

ulli getSum (ulli curNodeIndex, ulli left, ulli right) {
  ulli curLeft = array[curNodeIndex].left;
  ulli curRight = array[curNodeIndex].right;
  if (curRight < left || curLeft > right) return 0;
  if (left <= curLeft && curRight <= right) {
    return array[curNodeIndex].v * (curRight - curLeft + 1) + array[curNodeIndex].sum;
  }
  if (curLeft != curRight) {
    ulli temp = array[curNodeIndex].v;
    array[curNodeIndex].sum += (temp * (curRight - curLeft + 1));
    array[curNodeIndex * 2].v += temp;
    array[1 + curNodeIndex * 2].v += temp;
    array[curNodeIndex].v  = 0;
    return getSum(curNodeIndex * 2, left, right) + getSum(1 + curNodeIndex * 2, left, right);
  }
}

void update (ulli curNodeIndex, ulli left, ulli right, ulli v) {
  ulli curLeft = array[curNodeIndex].left;
  ulli curRight = array[curNodeIndex].right;
  if (curRight < left || curLeft > right) return;
  if (left <= curLeft && curRight <= right) {
    array[curNodeIndex].v += v;
    return;
  }
  if (curLeft != curRight) {
    array[curNodeIndex].sum += (v * (min(curRight,right) - max(curLeft,left) + 1));
    update(curNodeIndex * 2, left, right, v);
    update (1 + curNodeIndex * 2, left, right, v);
    return;
  }
}

int main () {
  ulli t, c;
  ulli command, p, q;
  ulli v, rs;
  cin >> t;
  for (ulli z = 0; z < t; z++) {
    cin >> n >> c;
    initialization();
    for (ulli queryNb = 0; queryNb < c; queryNb ++) {
      cin >> command >> p >> q;
      if (command == 0) {
        cin >> v;
        update (1, p, q, v);
      }
      else {
        rs = getSum(1, p, q);
        cout << rs << "\n";
      }
    }
    delete [] array;
  }
}
