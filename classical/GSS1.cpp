// GSS1 - Can you answer these queries I
// http://www.spoj.com/problems/GSS1/

#include <iostream>
#include <stdio.h>
using namespace std;

struct myElement {
  int left;
  int right;
  int maxSum;
  int maxSumLeft;
  int maxSumRight;
};

int n;
int a[50001];
int dp[50001];
int nbOfNodes;
myElement * array;

void initialize () {
  int k = 1;
  while (k < n)
    k = k << 1;
  nbOfNodes = 2 * k - 1;
  array = new myElement[nbOfNodes+1];
}

int max (int a, int b) {
  return a > b ? a : b;
}

int min (int a, int b) {
  return a < b ? a : b;
}

// Time complexity of this function: O(n)
// It is just like doing some 'complicated' tree traversal
void constructTree (int nodeNb) {
  if (nodeNb == 1) {
    array[nodeNb].left = 1;
    array[nodeNb].right = n;
  }
  else {
    int parent_left = array[nodeNb/2].left;
    int parent_right = array[nodeNb/2].right;
    if (nodeNb & 1) {
      array[nodeNb].left = 1 + (parent_left + parent_right)/2;
      array[nodeNb].right = parent_right;
    }
    else {
      array[nodeNb].left = parent_left;
      array[nodeNb].right = (parent_left + parent_right)/2;
    }
  }


  int curLeft = array[nodeNb].left;
  int curRight = array[nodeNb].right;
  int curMiddle = (curRight + curLeft) / 2;

  if (array[nodeNb].left == array[nodeNb].right) {
    array[nodeNb].maxSum = a[array[nodeNb].left];
    array[nodeNb].maxSumLeft = array[nodeNb].maxSum;
    array[nodeNb].maxSumRight = array[nodeNb].maxSum;
    //cout << curLeft << " " << curRight << "\n";
    //cout << "maxSum = " << array[nodeNb].maxSum << "\n";
    return;
  }

  constructTree (2 * nodeNb);
  constructTree (2 * nodeNb + 1);

  array[nodeNb].maxSumLeft = array[2 * nodeNb].maxSumLeft;
  array[nodeNb].maxSumLeft = max(array[nodeNb].maxSumLeft, dp[curMiddle] - dp[curLeft-1] + array[nodeNb*2+1].maxSumLeft);

  array[nodeNb].maxSumRight = array[2 * nodeNb + 1].maxSumRight;
  array[nodeNb].maxSumRight = max(array[nodeNb].maxSumRight, dp[curRight] - dp[curMiddle] + array[nodeNb*2].maxSumRight);

  array[nodeNb].maxSum = array[nodeNb].maxSumLeft;
  array[nodeNb].maxSum = max(array[nodeNb].maxSum, array[nodeNb].maxSumRight);
  array[nodeNb].maxSum = max(array[nodeNb].maxSum, array[nodeNb*2].maxSum);
  array[nodeNb].maxSum = max(array[nodeNb].maxSum, array[nodeNb*2 + 1].maxSum);
  array[nodeNb].maxSum = max(array[nodeNb].maxSum, array[nodeNb*2].maxSumRight + array[nodeNb*2 + 1].maxSumLeft);

  //cout << curLeft << " " << curRight << "\n";
  //cout << "maxSum = " << array[nodeNb].maxSum << "\n";
  return;
}

// Time complexity: O(log N)
int getMaxSum (int nodeNb, int left, int right, int *tmpLeft, int *tmpRight) {
  int curLeft = array[nodeNb].left;
  int curRight = array[nodeNb].right;
  if (curRight < left || curLeft > right) {
    (*tmpLeft) = -1000000000;
    (*tmpRight) = -1000000000;
    return -1000000000;
  }
  if (left <= curLeft && curRight <= right) {
    (*tmpLeft) = array[nodeNb].maxSumLeft;
    (*tmpRight) = array[nodeNb].maxSumRight;
    return array[nodeNb].maxSum;
  }
  if (curLeft != curRight) {
    int maxLeft1, maxRight1;
    int maxLeft2, maxRight2;
    int curMiddle = (curLeft + curRight) / 2;
    int max1 = getMaxSum(nodeNb * 2, left, right, &maxLeft1, &maxRight1);
    int max2 = getMaxSum(nodeNb * 2 + 1, left, right, &maxLeft2, &maxRight2);
    int curMax;

    (*tmpLeft) = maxLeft1;
    if (left <= curMiddle && curMiddle <= right)
      (*tmpLeft) = max((*tmpLeft), dp[curMiddle] - dp[max(curLeft,left)-1] + maxLeft2);

    (*tmpRight) = maxRight2;
    if (left <= curMiddle && curMiddle <= right)
      (*tmpRight) = max((*tmpRight), dp[min(curRight,right)] - dp[curMiddle] + maxRight1);

    curMax = (*tmpLeft);
    curMax = max(curMax, (*tmpRight));
    curMax = max(curMax, max1);
    curMax = max(curMax, max2);
    curMax = max(curMax , maxRight1 + maxLeft2);

    return curMax;
  }
}


int main () {
  int nbQuery, tempX, tempY;
  int tempL, tempR;
  int finalRs;
  dp[0] = 0;
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &a[i]);
    dp[i] = dp[i-1] + a[i];
  }
  initialize();
  constructTree(1);
  scanf ("%d", &nbQuery);
  for (int z = 0; z < nbQuery; z++) {
    scanf ("%d %d", &tempX, &tempY);
    finalRs = getMaxSum (1, tempX, tempY, &tempL, &tempR);
    cout << finalRs << "\n";
  }

  delete [] array;
}
