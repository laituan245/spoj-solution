// AGGRCOW - Aggressive cows
// http://www.spoj.com/problems/AGGRCOW/
// laituanksa245

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int a[100000];
int finalAns;
int n, c;

int min (int a, int b) {
  if (a < b) return a;
  return b;
}

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

void swap (int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void quickSort (int left, int right) {
  if (left >= right) return;
  if (left + 1 == right) {
    if (a[left] > a[right])
      swap (a[left], a[right]);
    return;
  }

  int pivotIndex = left + rand() % (right-left+1);
  int pivot = a[pivotIndex];
  swap (a[left], a[pivotIndex]);
  int tempIndex = left + 1;
  for (int i = left + 1; i <= right; i++)
    if (a[i] <= pivot) {
      swap(a[i], a[tempIndex]);
      tempIndex++;
    }

  a[left] = a[tempIndex-1];
  a[tempIndex-1] = pivot;
  quickSort (left, tempIndex-2);
  quickSort (tempIndex, right);
}

bool isPossible (int bound) {
  int prev = 0;
  int nbOfCows = c - 1;
  for (int i = 1; i < n; i++)
    if (a[i] - a[prev] >= bound) {
      prev = i;
      nbOfCows = nbOfCows - 1;
    }
  return (nbOfCows <= 0);
}

void binarySearch (int lowerBound, int upperBound) {
  if (lowerBound > upperBound) return;
  if (lowerBound == upperBound) {
    if (isPossible(lowerBound))
      finalAns = max(finalAns, lowerBound);
    return;
  }

  int mid = (lowerBound + upperBound) / 2;
  bool isMidPossible = isPossible(mid);
  if (!isMidPossible)
    binarySearch(lowerBound, mid-1);
  else {
    finalAns = max(finalAns, mid);
    binarySearch(mid+1, upperBound);
  }

}

int main () {
  int t;
  int lowerBound, upperBound;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {
    scanf ("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
      scanf ("%d", &a[i]);
    quickSort (0, n-1);

    upperBound = a[n-1] - a[0];
    lowerBound = 1000000001;
    for (int i = 1; i < n; i++)
      lowerBound = min (lowerBound, a[i] - a[i-1]);

    finalAns = -1;
    binarySearch(lowerBound, upperBound);

    printf ("%d\n", finalAns);
  }
}
