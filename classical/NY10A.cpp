// NY10A - Penney Game
// http://www.spoj.com/problems/NY10A/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int main () {
  int t;
  int datasetNb;
  map <string, int> myMap;
  string threeCoin[8];
  string tmpStr;
  threeCoin[0] = "TTT"; threeCoin[1] = "TTH"; threeCoin[2] = "THT";
  threeCoin[3] = "THH"; threeCoin[4] = "HTT"; threeCoin[5] = "HTH";
  threeCoin[6] = "HHT"; threeCoin[7] = "HHH";
  string tossSequence;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> datasetNb;
    tossSequence = "";
    while (tossSequence == "")
      cin >> tossSequence;
    myMap.clear();
    for (int i = 0; i < 38; i++) {
      tmpStr = "";
      tmpStr = tmpStr + tossSequence[i];
      tmpStr = tmpStr + tossSequence[i + 1];
      tmpStr = tmpStr + tossSequence[i + 2];
      myMap[tmpStr]++;
    }
    cout << datasetNb;
    for (int i = 0; i < 8; i++)
      cout << " " << myMap[threeCoin[i]];
    cout << "\n";
  }
}
