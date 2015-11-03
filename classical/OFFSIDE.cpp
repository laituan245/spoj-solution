// OFFSIDE - He is offside!
// http://www.spoj.com/problems/OFFSIDE/

#include <iostream>
#include <stdio.h>
using namespace std;

void swap (int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void sort (int * array, int length) {
  for (int i = 0; i < length; i++)
    for (int j = i + 1; j < length; j++)
      if (array[i] > array[j])
        swap (array[i], array[j]);
}

int main () {
  int a, d;
  int posA[11];
  int posD[11];
  while (true) {
    scanf ("%d %d", &a, &d);
    if (a == 0 && d == 0)
      break;
    for (int i = 0; i < a; i++)
      scanf ("%d", &posA[i]);
    for (int i = 0; i < d; i++)
      scanf ("%d", &posD[i]);

    sort (posA, a);
    sort (posD, d);
    if (posA[0] >= posD[1])
      cout << "N\n";
    else
      cout << "Y\n";
  }
}
