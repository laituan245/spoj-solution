// CRAN04 - Audition
// http://www.spoj.com/problems/CRAN04/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#define lli long long int
using namespace std;


int main () {
  int t;
  lli n, k;
  lli nbOfOnes;
  lli finalRs, tempLow, tempHigh;
  vector <lli> indexOfOnes;
  string Queue;
  cin >> t;
  for (int z = 0; z < t; z++) {
    finalRs = 0;
    nbOfOnes = 0;
    indexOfOnes.clear();
    cin >> n >> k;
    cin >> Queue;

    indexOfOnes.push_back(-1);
    for (int i = 0; i < Queue.length(); i++)
      if (Queue[i] == '1') {
        indexOfOnes.push_back(i);
        nbOfOnes ++;
      }
    indexOfOnes.push_back(n);

    if (nbOfOnes < k)
      cout << "0\n";
    else if (k == 0) {
      finalRs = 0;
      lli temp;
      for (int i = 1; i <= nbOfOnes + 1; i++) {
        temp = indexOfOnes[i]-indexOfOnes[i-1]-1;
        finalRs += ((temp * (temp+1))/2);
      }
      cout << finalRs << "\n";
    }
    else {
      for (int i = 1; i <= nbOfOnes; i++) {
        if (i + k - 1 > nbOfOnes)
          break;
        else {
          int j = i + k - 1;
          tempLow = indexOfOnes[i] - indexOfOnes[i-1];
          tempHigh = indexOfOnes[j+1] - indexOfOnes[j];
          finalRs += (tempLow * tempHigh);
        }
      }
      cout << finalRs << "\n";
    }
  }
}
