// NOTATRI - Not a Triangle
// http://www.spoj.com/problems/NOTATRI/
// laituanksa245

#include <stdio.h>
using namespace std;

void swap (int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void quickSort (int *a, int left, int right) {
  if (left >= right) return;
  if (left + 1 == right) {
    if (a[left] > a[right])
      swap (a[left], a[right]);
    return;
  }

  int pivot = a[left];
  int tempIndex = left + 1;
  for (int i = left + 1; i <= right; i++)
    if (a[i] <= pivot) {
      swap(a[i], a[tempIndex]);
      tempIndex++;
    }

  a[left] = a[tempIndex-1];
  a[tempIndex-1] = pivot;
  quickSort (a, left, tempIndex-2);
  quickSort (a, tempIndex, right);
}

int binarySearch (int * a, int sum, int left, int right) {
  if (left > right)
    return -1;  // Failure
  if (left == right) {
    if (sum >= a[left])
      return left;
    return -1;  // Failure
  }

  int mid = (left + right) / 2;
  if (a[mid] > sum)
    return binarySearch(a, sum, left, mid-1);
  else if (a[mid] <= sum) {
    if (a[mid+1] > sum)
      return mid;
    return binarySearch(a, sum, mid + 1, right);
  }
}

int main () {
  int n;
  int tempIndex;
  int finalRs;
  int length[2000];
  while (true) {
    scanf ("%d", &n);
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf ("%d", &length[i]);

    finalRs = 0;
    quickSort(length, 0, n-1);
    for (int i = 0; i < n-2; i++)
      for (int j = i+1; j < n-1; j++) {
        tempIndex = binarySearch (length, length[i] + length[j], j+1, n-1);
        if (tempIndex != -1)
          finalRs += (n-1-tempIndex);
        else
          finalRs += (n-1-j);
      }
    printf ("%d\n", finalRs);
  }

}
