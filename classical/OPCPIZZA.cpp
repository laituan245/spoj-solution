// OPCPIZZA - Pizzamania
// http://www.spoj.com/problems/OPCPIZZA/

#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

int main () {
  int n, t;
  int money[100000];
  int m, temp;
  int finalRs;
  unordered_map <int, int> myMap;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {
    myMap.clear();
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf ("%d", &money[i]);
      myMap[money[i]] ++;
    }

    finalRs = 0;
    for (int i = 0; i < n; i++) {
      temp = m - money[i];
      finalRs += myMap[temp];
      if (temp == money[i])
        finalRs -= 1;
    }

    finalRs = finalRs / 2;
    cout << finalRs << "\n";
  }
}
