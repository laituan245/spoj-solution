// SOLDIER - Help the soldier
// http://www.spoj.com/problems/SOLDIER/
#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector <int> equipmentPrice[8];
vector <int> equipmentQuality[8];
int finalRs;

void swap (int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int max (int a, int b) {
  return a > b ? a : b;
}

bool isPossible (int minQuality) {
  bool foundSth;
  int minTotalPrice = 0;
  for (int type = 1; type <= 6; type ++) {
    foundSth = false;
    for (int i = 0; i < equipmentQuality[type].size(); i++) {
      if (equipmentQuality[type][i] >= minQuality) {
        minTotalPrice += equipmentPrice[type][i];
        foundSth = true;
        break;
      }
    }
    if (!foundSth)
      return false;
  }
  return minTotalPrice <= t;
}

void binarySearch (int lowerBound, int upperBound) {
  if (lowerBound <= upperBound) {
    int mid = (lowerBound + upperBound) / 2;
    if (isPossible (mid)) {
      finalRs = max (finalRs, mid);
      binarySearch (mid+1, upperBound);
    }
    else
      binarySearch (lowerBound, mid-1);
  }
}

int main () {
  int tmpType, tmpPrice, tmpQuality;
  bool possible;

  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> tmpType >> tmpPrice >> tmpQuality;
    equipmentPrice[tmpType].push_back (tmpPrice);
    equipmentQuality[tmpType].push_back (tmpQuality);
  }
  possible = true;
  for (int type = 1; type <= 6; type++)
    if (equipmentPrice[type].size() == 0) {
      possible = false;
      break;
    }
  if (!possible)
    cout << "0\n";
  else {
    // Sorting
    for (int type = 1; type <= 6; type++)
      for (int i = 0; i < equipmentPrice[type].size(); i++)
        for (int j = i + 1; j < equipmentPrice[type].size(); j++)
          if (equipmentPrice[type][i] > equipmentPrice[type][j]) {
            swap (equipmentPrice[type][i], equipmentPrice[type][j]);
            swap (equipmentQuality[type][i], equipmentQuality[type][j]);
          }

    finalRs = 0;
    binarySearch(1, t-1);
    cout << finalRs << "\n";
  }
}
