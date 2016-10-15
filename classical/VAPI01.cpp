// VAPI01 - Vitaliy and Pie
// http://www.spoj.com/problems/VAPI01/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main () {
  int t; // nb of test cases
  int n; // nb of rooms
  int final_rs;
  int key_count[26];
  string s;
  scanf("%d", &t);
  for (int z = 0; z < t; z++) {
    scanf("%d", &n);
    s = "";
    while (s == "")
      cin >> s;
    final_rs = 0;
    for (int i = 0; i < 26; i++)
      key_count[i] = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i % 2 == 0) {
        key_count[((int) s[i]) - 97]++;
      } else {
        if (key_count[((int) s[i]) - 65] == 0)
          final_rs++;
        else
          key_count[((int) s[i]) - 65]--;
      }
    }
    cout << final_rs << "\n";
  }
}
