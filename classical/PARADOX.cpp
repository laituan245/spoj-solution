// PARADOX - Paradox
// http://www.spoj.com/problems/PARADOX/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int t, n;
int tmpNb;
int componentCount;
string tmpStr;
vector <int> adjList [201];
map <int, int> getComponent;
bool visited[201];

void DFS (int x) {
  visited[x] = true;
  getComponent[x] = componentCount;
  for (int z = 0; z < adjList[x].size(); z++)
    if (visited[adjList[x][z]] == false)
      DFS(adjList[x][z]);
}

int main () {

  while (true) {
    cin >> n;
    if (n == 0)
      break;

    getComponent.clear();
    for (int i = 1; i <= 2 * n; i++) {
      adjList[i].clear();
      visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
      cin >> tmpNb >> tmpStr;
      if (tmpStr == "true") {
        adjList[i].push_back (tmpNb);
        adjList[tmpNb].push_back (i);
        adjList[i + n].push_back (tmpNb + n);
        adjList[tmpNb + n].push_back (i+n);
      }
      else {
        adjList[i].push_back (tmpNb + n);
        adjList[tmpNb + n].push_back (i);
        adjList[i + n].push_back (tmpNb);
        adjList[tmpNb].push_back (i+n);
      }
    }

    componentCount = 0;
    for (int i = 1; i <= 2 * n; i++)
      if (visited[i] == false) {
        DFS(i);
        componentCount++;
      }

    bool notParadox = true;
    for (int i = 1; i <= n; i++)
      if (getComponent[i] == getComponent[i+n])
        notParadox = false;

    if (notParadox)
      cout << "NOT PARADOX\n";
    else
      cout << "PARADOX\n";
  }
}
