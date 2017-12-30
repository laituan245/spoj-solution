// BROKEN - Broken Keyboard
// http://www.spoj.com/problems/BROKEN/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  int m, result, index, nb_unique_chars, current_length, begin_index;
  string text;
  unordered_map <char, int> count;
  while (true) {
    cin >> m;
    if (m == 0) break;
    text = "";
    while (text == "") getline(cin, text);
    count.clear();
    result = 0; index = 0; nb_unique_chars = 0;
    current_length = 0; begin_index = 0;
    while (index < text.length()) {
      count[text[index]]++;
      if (count[text[index]] == 1) nb_unique_chars++;
      if (nb_unique_chars > m) {
        if (current_length > result) result = current_length;
        count[text[begin_index]] --;
        if (count[text[begin_index]] == 0) nb_unique_chars--;
        begin_index++;
      } else {
        current_length++;
      }
      index++;
    }
    if (nb_unique_chars <= m) {
      if (current_length > result) result = current_length;
    }
    cout << result << "\n";
  }
}
