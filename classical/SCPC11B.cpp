// SCPC11B - Alaska
// http://www.spoj.com/problems/SCPC11B/
// laituanksa245

#include <iostream>
using namespace std;

void swap (int &a, int &b) {
  int tg = a;
  a = b;
  b = tg;
}

void quickSort (int * a, int left, int right) {
  if (left >= right) return;
  if (left + 1 == right) {
    if (a[left] > a[right])
      swap (a[left], a[right]);
    return;
  }

  int pivot = a[left];
  int tempIndex = left + 1;
  for (int i = left + 1; i <= right; i++)
    if (a[i] < pivot) {
      swap (a[i], a[tempIndex]);
      tempIndex ++;
    }

  a[left] = a[tempIndex-1];
  a[tempIndex-1] = pivot;

  quickSort (a, left, tempIndex-2);
  quickSort (a, tempIndex, right);
}

int main () {
  bool possible = true;
  int n;
  int a[1423];
  bool has1422;
  while (cin >> n) {
    has1422 = false;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1422)
        has1422 = true;
    }
    if (!has1422) {
      a[n] = 1422;
      n++;
    }
    quickSort(a, 0, n-1);
    possible = true;
    if (a[0] != 0)
      possible = false;
    for (int i = 1; i < n; i++)
      if (a[i] - a[i-1] > 200)
        possible = false;
    if (!has1422) {
      if (1422-a[n-2] > 100)
        possible = false;
    }
    if (possible)
      cout << "POSSIBLE\n";
    else
      cout << "IMPOSSIBLE\n";
  }
}
