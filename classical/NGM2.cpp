// NGM2 - Another Game With Numbers
// http://www.spoj.com/problems/NGM2/

#include <iostream>
#include <vector>
using namespace std;

long long int n;
int k;
long long int x[15];
long long int finalRs;
long long int tmpNb, tmpGCD;
vector <long long int> subSet;

long long int gcd (long long int a, long long int b) {
  long long int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void backtracking (int cur) {
  for (int i = 0; i < 2; i++) {
    if (i == 1)
      subSet.push_back(x[cur]);
    if (cur == k - 1) {
      if (subSet.size() > 0) {
        tmpNb = 1;
        for (int i = 0; i < subSet.size(); i++) {
          tmpGCD = gcd (tmpNb, subSet[i]);
          tmpNb = (tmpNb / tmpGCD) * subSet[i];
        }
        if (subSet.size() % 2 == 1)
          finalRs += (n / tmpNb);
        else
          finalRs -= (n / tmpNb);
      }
    }
    else
      backtracking (cur + 1);
    if (i == 1)
      subSet.pop_back();
  }
}

int main () {
  cin >> n >> k;
  for (int i = 0; i < k; i++)
    cin >> x[i];
  finalRs = 0;
  subSet.clear();
  backtracking(0);
  finalRs = n - finalRs;
  cout << finalRs << "\n";
}
