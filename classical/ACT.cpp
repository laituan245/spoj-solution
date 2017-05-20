// http://www.spoj.com/problems/ACT/
// ACT - Alpha Centauri Tennis
#include <iostream>
#include <string>
using namespace std;

int name_to_nb(char c) {
    return int(c) - 65;
}

char nb_to_name(int nb) {
    return char(nb + 65);
}

int main() {
    int t, n;
    string s;
    int game_scores[10];
    int game_won_in_this_set[10];
    int set_won_in_this_match[10];
    int winner;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> s;
        cout << s[s.length()-1] << "\n";
    }
}
