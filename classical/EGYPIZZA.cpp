// EGYPIZZA - Pizza
// http://www.spoj.com/problems/EGYPIZZA/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main () {
  int n;
  int finalRs = 1;
  int a,b;
  int count1 = 0, count2 = 0, count3 = 0;
  double tmpAns;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d/%d", &a, &b);
    if (a == 1 && b == 2)
      count1++;
    else if (a == 3 && b == 4)
      count2++;
    else if (a == 1 && b == 4)
      count3++;
  }
  finalRs += count2;
  count3 = max(0, count3 - count2);
  if (count3 == 0) {
    finalRs += (count1 / 2);
    if (count1 % 2 != 0)
      finalRs ++;
  }
  else {
    tmpAns = count3 + count1 * 2;
    tmpAns = tmpAns / 4;
    finalRs += ceil(tmpAns);
  }
  cout << finalRs << "\n";
}
