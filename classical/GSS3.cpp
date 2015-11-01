// GSS3 - Can you answer these queries III
// http://www.spoj.com/problems/GSS3/en/
#include <iostream>
#include <stdio.h>
using namespace std;

struct myElement {
  int left, right, sum, mS, mSL, mSR;
};

int n;
int a[50001];
int pos[50001];
int nbOfNodes;
myElement * arr;

void initialize () {
  int k = 1;
  while (k < n)
    k = k << 1;
  nbOfNodes = 2 * k - 1;
  arr = new myElement[nbOfNodes+1];
}

void constructTree (int nodeNb) {
  if (nodeNb == 1) {
    arr[nodeNb].left = 1;
    arr[nodeNb].right = n;
  }
  else {
    int parent_left = arr[nodeNb/2].left;
    int parent_right = arr[nodeNb/2].right;
    if (nodeNb & 1) {
      arr[nodeNb].left = 1 + (parent_left + parent_right)/2;
      arr[nodeNb].right = parent_right;
    }
    else {
      arr[nodeNb].left = parent_left;
      arr[nodeNb].right = (parent_left + parent_right)/2;
    }
  }

  int curLeft = arr[nodeNb].left;
  int curRight = arr[nodeNb].right;
  int curMiddle = (curRight + curLeft) / 2;

  if (arr[nodeNb].left == arr[nodeNb].right) {
    arr[nodeNb].mS = a[arr[nodeNb].left];
    arr[nodeNb].sum = arr[nodeNb].mS;
    arr[nodeNb].mSL = arr[nodeNb].mS;
    arr[nodeNb].mSR = arr[nodeNb].mS;
    pos[arr[nodeNb].left] = nodeNb;
    return;
  }

  constructTree (2 * nodeNb);
  constructTree (2 * nodeNb + 1);

  arr[nodeNb].mSL = arr[2 * nodeNb].mSL;
  arr[nodeNb].mSL = max(arr[nodeNb].mSL, arr[nodeNb*2].sum + arr[nodeNb*2+1].mSL);
  arr[nodeNb].mSR = arr[2 * nodeNb + 1].mSR;
  arr[nodeNb].mSR = max(arr[nodeNb].mSR, arr[nodeNb*2 + 1].sum + arr[nodeNb*2].mSR);
  arr[nodeNb].mS = arr[nodeNb].mSL;
  arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb].mSR);
  arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2].mS);
  arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2 + 1].mS);
  arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2].mSR + arr[nodeNb*2 + 1].mSL);
  arr[nodeNb].sum = arr[nodeNb*2].sum + arr[nodeNb * 2 + 1].sum;
  return;
}

int getmS (int nodeNb, int left, int right, int *tmpLeft, int *tmpRight, int * sum) {
  int curLeft = arr[nodeNb].left;
  int curRight = arr[nodeNb].right;
  if (curRight < left || curLeft > right) {
    (*tmpLeft) = -1000000000;
    (*tmpRight) = -1000000000;
    (*sum) = 0;
    return -1000000000;
  }
  if (left <= curLeft && curRight <= right) {
    (*tmpLeft) = arr[nodeNb].mSL;
    (*tmpRight) = arr[nodeNb].mSR;
    (*sum) = arr[nodeNb].sum;
    return arr[nodeNb].mS;
  }
  if (curLeft != curRight) {
    int maxLeft1, maxRight1, sum1;
    int maxLeft2, maxRight2, sum2;
    int curMiddle = (curLeft + curRight) / 2;
    int max1 = getmS(nodeNb * 2, left, right, &maxLeft1, &maxRight1, &sum1);
    int max2 = getmS(nodeNb * 2 + 1, left, right, &maxLeft2, &maxRight2, &sum2);
    int curMax;
    (*tmpLeft) = maxLeft1;
    if (left <= curMiddle && curMiddle <= right)
      (*tmpLeft) = max((*tmpLeft), sum1 + maxLeft2);
    (*tmpRight) = maxRight2;
    if (left <= curMiddle && curMiddle <= right)
      (*tmpRight) = max((*tmpRight), sum2 + maxRight1);
    (*sum) = sum1 + sum2;
    curMax = (*tmpLeft);
    curMax = max(curMax, (*tmpRight));
    curMax = max(curMax, max1);
    curMax = max(curMax, max2);
    curMax = max(curMax , maxRight1 + maxLeft2);
    return curMax;
  }
}

int update (int nodeNb) {
  int curLeft = arr[nodeNb].left;
  int curRight = arr[nodeNb].right;
  int curMiddle = (curLeft + curRight) / 2;
  if (curLeft == curRight) {
    arr[nodeNb].mS = a[arr[nodeNb].left];
    arr[nodeNb].sum = arr[nodeNb].mS;
    arr[nodeNb].mSL = arr[nodeNb].mS;
    arr[nodeNb].mSR = arr[nodeNb].mS;
  }
  else {
    arr[nodeNb].mSL = arr[2 * nodeNb].mSL;
    arr[nodeNb].mSL = max(arr[nodeNb].mSL, arr[nodeNb*2].sum + arr[nodeNb*2+1].mSL);
    arr[nodeNb].mSR = arr[2 * nodeNb + 1].mSR;
    arr[nodeNb].mSR = max(arr[nodeNb].mSR, arr[nodeNb*2 + 1].sum + arr[nodeNb*2].mSR);
    arr[nodeNb].mS = arr[nodeNb].mSL;
    arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb].mSR);
    arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2].mS);
    arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2 + 1].mS);
    arr[nodeNb].mS = max(arr[nodeNb].mS, arr[nodeNb*2].mSR + arr[nodeNb*2 + 1].mSL);
    arr[nodeNb].sum = arr[nodeNb*2].sum + arr[nodeNb * 2 + 1].sum;
  }
  if (!(curLeft == 1 && curRight == n)) {
    update (nodeNb / 2);
  }
}

int main () {
  int nbQuery, tempX, tempY;
  int tempL, tempR, tempS;
  int command;
  int finalRs;
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &a[i]);
  initialize();
  constructTree(1);
  scanf ("%d", &nbQuery);
  for (int z = 0; z < nbQuery; z++) {
    scanf ("%d %d %d", &command, &tempX, &tempY);
    if (command) {
      finalRs = getmS (1, tempX, tempY, &tempL, &tempR, &tempS);
      cout << finalRs << "\n";
    }
    else {
      a[tempX] = tempY;
      update (pos[tempX]);
    }
  }
  delete [] arr;
}
