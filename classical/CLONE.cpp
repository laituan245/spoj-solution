// CLONE - Find the Clones
// http://www.spoj.com/problems/CLONE/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main () {
  int n, m;
  string DNA;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    unordered_map <string, int> strCount;
    unordered_map <int, int> intCount;
    intCount[0] = n;
    for (int i = 0; i < n; i++) {
      cin >> DNA;
      intCount[strCount[DNA]] --;
      strCount[DNA] ++;
      intCount[strCount[DNA]] ++;
    }
    for (int i = 1; i <= n; i++)
      cout << intCount[i] << "\n";
  }
}
