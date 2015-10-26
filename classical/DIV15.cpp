// DIV15 - Divisibility by 15
// http://www.spoj.com/problems/DIV15/

#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

int charToDigit (char c) {
  string tmpStr = "0123456789";
  for (int i = 0; i < 10; i++)
    if (tmpStr[i] == c)
      return i;
}

int main () {
  int t;
  string inputStr;
  unordered_map <int, int> myMap;
  bool possible = true;
  int lastDigit;
  int tempSum;
  cin >> t;
  for (int z = 0; z < t; z++) {
    myMap.clear ();
    cin >> inputStr;
    for (int i = 0; i < inputStr.length(); i++)
      myMap[charToDigit(inputStr[i])] ++;

    if (myMap[0] == inputStr.length())
      cout << "0\n";
    else if (myMap[0] == 0 && myMap[5] == 0)
      cout << "impossible\n";
    else {
      if (myMap[0] > 0) {
        lastDigit = 0;
        myMap[0] -= 1;
      }
      else {
        lastDigit = 5;
        myMap[5] -= 1;
      }
      tempSum = lastDigit;
      for (int i = 1; i < 10; i++)
        tempSum += i * myMap[i];
      possible = true;

      if (tempSum % 3 == 1) {
        possible = false;
        if (myMap[1] > 0 || myMap[4] > 0 || myMap[7] > 0) {
          possible = true;
          for (int i = 1; i <= 7; i+=3)
            if (myMap[i]) {
              myMap[i] -= 1;
              break;
            }
        }
        else if (myMap[2] + myMap[5] + myMap[8] >= 2) {

          possible = true;
          int tempCount = 2;
          for (int i = 2; i <= 8; i+=3) {
            while (myMap[i]) {
              myMap[i] -= 1;
              tempCount --;
              if (tempCount == 0)
                break;
            }
            if (tempCount == 0)
              break;
          }
        }
      }
      else if (tempSum % 3 == 2) {
        possible = false;
        if (myMap[2] > 0 || myMap[5] > 0 || myMap[8] > 0) {
          possible = true;
          for (int i = 2; i <= 8; i+=3)
            if (myMap[i]) {
              myMap[i] -= 1;
              break;
            }
        }
        else if (myMap[1] + myMap[4] + myMap[7] >= 2) {
          possible = true;
          int tempCount = 2;
          for (int i = 1; i <= 7; i+=3) {
            while (myMap[i]) {
              myMap[i] -= 1;
              tempCount --;
              if (tempCount == 0)
                break;
            }
            if (tempCount == 0)
              break;
          }
        }
      }
      if (!possible)
        cout << "impossible\n";
      else  {
        bool noOtherDigit = true;
        for (int i = 1; i < 10; i++)
          if (myMap[i] != 0)
            noOtherDigit = false;
        if (noOtherDigit && lastDigit == 0)
          cout << "0\n";
        else {
          for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < myMap[i]; j++)
              cout << i;
          }
          cout << lastDigit;
          cout << "\n";
        }
      }
    }
  }
}
