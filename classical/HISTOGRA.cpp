// HISTOGRA - Largest Rectangle in a Histogram
// http://www.spoj.com/problems/HISTOGRA/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main () {
  long long int n, temp;
  long long int dp1[100001];
  long long int dp2[100001];
  while (true) {
    cin >> n;
    if (n == 0) break;
    stack < long long int> myStack;
    vector < long long int> a;
    a.push_back(-1);
    for ( long long int i = 0; i < n; i++) {
      cin >> temp;
      a.push_back (temp);
    }
    a.push_back(-1);
    myStack.push(1);
    for ( long long int i = 2; i <= n+1; i++) {
      if (a[i] >= a[myStack.top()])
        myStack.push(i);
      else {
        while (!myStack.empty() && a[i] < a[myStack.top()]) {
          dp1[myStack.top()] = i;
          myStack.pop();
        }
        myStack.push(i);
      }
    }

    while (!myStack.empty())
      myStack.pop ();

    myStack.push(n);
    for ( long long int i = n-1; i >= 0; i--) {
      if (a[i] >= a[myStack.top()])
        myStack.push(i);
      else {
        while (!myStack.empty() && a[i] < a[myStack.top()]) {
          dp2[myStack.top()] = i;
          myStack.pop();
        }
        myStack.push(i);
      }
    }

     long long int finalRs = 0;
     long long int tempCal = 0;
    for ( long long int i = 1; i <= n; i++) {
      tempCal = a[i] * ((i - (1 + dp2[i]) + 1) + (dp1[i]-1 - i + 1) - 1);
      if (tempCal > finalRs)
        finalRs = tempCal;
    }
    cout << finalRs << "\n";
  }
}
