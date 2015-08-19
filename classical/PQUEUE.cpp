// PQUEUE - Printer Queue
// http://www.spoj.com/problems/PQUEUE/
// laituanksa245

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

int min (int a, int b) {
  if (a < b) return a;
  return b;
}

int main () {
  int t;
  int n, m, tempIndex;
  int jobPriority[100];
  int finalAns;
  bool printed[100];
  map <int, int> count;
  int curLargest;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {

    // Some initialization
    finalAns = 0;
    for (int i = 0; i < 10; i++)
      count[i] = 0;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf ("%d", &jobPriority[i]);
      count[jobPriority[i]] ++;
      printed[i] = false;
    }

    tempIndex = 0;
    while (true)
    {
      while (printed[tempIndex]) {
        tempIndex = (tempIndex + 1) % n;
      }
      for (int j = 9; j >= 0; j--)
        if (count[j] != 0) {
          curLargest = j;
          break;
        }
      if (jobPriority[tempIndex] == curLargest) {
        printed[tempIndex] = true;
        count[curLargest] --;
        finalAns ++;
        if (tempIndex == m)
          break;
      }
      tempIndex = (tempIndex + 1) % n;
    }

    cout << finalAns << "\n";
  }
}
