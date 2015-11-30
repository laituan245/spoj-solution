// HELLOKIT - Hello Kitty
// http://www.spoj.com/problems/HELLOKIT/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
  string myStr;
  int n, strlength, nbCharPerLine;
  while (true) {
    myStr = "";
    while (myStr == "")
      cin >> myStr;
    if (myStr == ".")
      break;
    cin >> n;
    strlength = myStr.length();
    nbCharPerLine = n * strlength;
    for (int i = 0; i < strlength; i++) {
      for (int j = 0; j < nbCharPerLine; j++)
        cout << myStr[(j + i) % strlength];
      cout << "\n";
    }
  }
}
