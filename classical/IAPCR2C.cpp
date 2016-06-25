// IAPCR2C - Study Room
// http://www.spoj.com/problems/IAPCR2C/

#include <iostream>
using namespace std;

bool arr[100001];

int main () {
  int t, n, m, b, rs;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
      arr[i] = false;
    for (int i = 0; i < m; i++) {
      cin >> b;
      arr[b] = true;
      if (b + 1 <= n)
        arr[b+1] = true;
      if (b - 1 >= 1)
        arr[b-1] = true;
    }
    rs = 0;
    for (int i = 0; i <= n; i++)
      if (arr[i])
        rs = rs + 1;
    cout << "Case " << (z+1) << ": " << rs << "\n";
  }
}
