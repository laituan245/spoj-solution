// SBETS - Soccer Bets
// http://www.spoj.com/problems/SBETS/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main () {
  int t;
  string temp1, temp2;
  map <string, bool> appear;
  map <string, bool> lost;
  vector <string> teamNames;
  int score1, score2;
  int nbOfTeams = 0;
  cin >> t;
  for (int z = 0; z < t; z++) {
    appear.clear();
    lost.clear ();
    teamNames.clear ();
    nbOfTeams = 0;
    for (int i = 0; i < 16; i++) {
      cin >> temp1 >> temp2 >> score1 >> score2;
      if (appear[temp1] == false) {
        teamNames.push_back(temp1);
        nbOfTeams ++;
        appear[temp1] = true;
      }
      if (appear[temp2] == false) {
        teamNames.push_back(temp2);
        nbOfTeams ++;
        appear[temp2] = true;
      }
      if (score1 > score2)
        lost[temp2] = true;
      else
        lost[temp1] = true;
    }
    for (int i = 0; i < nbOfTeams; i++)
      if (lost[teamNames[i]] == false) {
        cout << teamNames[i] << "\n";
        break;
      }
  }
}
