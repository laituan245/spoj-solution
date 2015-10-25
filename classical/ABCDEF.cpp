// ABCDEF - ABCDEF
// http://www.spoj.com/problems/ABCDEF/

#include <iostream>
#include <unordered_map>
using namespace std;

int main () {
  int n;
  int s[100];
  unordered_map <int, int> myMap;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int eIndex = 0; eIndex < n; eIndex++)
    for (int fIndex = 0; fIndex < n; fIndex++)
      for (int dIndex = 0; dIndex < n; dIndex++)
        if (s[dIndex] != 0)
          myMap[(s[eIndex] + s[fIndex]) * s[dIndex]]++;

  long long int finalRs = 0;
  for (int aIndex = 0; aIndex < n; aIndex++)
    for (int bIndex = 0; bIndex < n; bIndex++)
      for (int cIndex = 0; cIndex < n; cIndex++)
          finalRs += myMap[s[aIndex] * s[bIndex] + s[cIndex]];

  cout << finalRs << "\n";
}
