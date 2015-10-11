  // NICEBTRE - Nice Binary Trees
  // http://www.spoj.com/problems/NICEBTRE/
  #include <stack>
  #include <string>
  #include <iostream>

  using namespace std;

  int max (int a, int b) {
    if (a > b)
      return a;
    return b;
  }

  int main () {
    int t;
    int count;
    int finalAns;
    int tempIndex = 0;
    int temp;
    string inputStr;
    cin >> t;
    for (int z = 0; z < t; z++) {
      cin >> inputStr;
      finalAns = 0;
      stack <int> branchStack;
      stack <int> depthStack;
      tempIndex = 0;
      depthStack.push (-1);
      while (tempIndex < inputStr.length()) {
        if (inputStr[tempIndex] == 'n') {
          branchStack.push (1);
          depthStack.push (depthStack.top() + 1);
          tempIndex++;
        }
        else {
          finalAns = max(finalAns, 1 + depthStack.top());
          while (!branchStack.empty() && branchStack.top () == 2) {
            branchStack.pop ();
            depthStack.pop ();
          }
          if (branchStack.empty())
            break;
          branchStack.pop();
          branchStack.push (2);
          tempIndex++;
        }
      }
      cout << finalAns << "\n";
    }
  }
