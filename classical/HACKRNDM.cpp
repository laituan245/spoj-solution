#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main () {
  unordered_map <int, int> count;
  int n, k, temp;
  vector <int> mVector;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    count[temp] ++;
    mVector.push_back(temp);
  }
  int finalRs = 0;
  for (int i = 0; i < n; i++) {
    finalRs += count[mVector[i]+k];
    finalRs += count[mVector[i]-k];
  }
  finalRs = finalRs / 2;
  cout << finalRs << "\n";
}
