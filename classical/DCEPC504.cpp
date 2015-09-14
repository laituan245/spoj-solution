#include <iostream>
#include <string>
using namespace std;

string findAns (int n, long long k, bool isMale) {
  if (n == 1) {
    if (isMale)
      return "Male";
    else
      return "Female";
  }

  bool shouldGoDownLeft = false;
  long long newK = k;
  long long tempNb = 1;
  for (int i = 0; i < n-2; i++)  {
    tempNb = tempNb * 2;
    if (tempNb >= k) {
      shouldGoDownLeft = true;
      break;
    }
  }
  if (tempNb >= k)
    shouldGoDownLeft = true;
  else
    newK = k - tempNb;

  if (shouldGoDownLeft) {
    if (isMale)
      return findAns (n-1, newK, true);
    else
      return findAns  (n-1, newK, false);
  }
  else {
    if (isMale)
      return findAns (n-1, newK, false);
    else
      return findAns  (n-1, newK, true);
  }

}

int main () {
  int t, n;
  long long k;
  string finalAns;

  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> k;
    finalAns = findAns(n, k, true);
    cout << finalAns << "\n";
  }
}
