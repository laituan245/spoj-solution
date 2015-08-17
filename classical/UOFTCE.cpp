// UOFTCE - A Brief Expedition
// www.spoj.com/problems/UOFTCE/
// laituanksa245

#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int startX, startY;
string mall[100];
bool visited[100][100];
int layer[100][100];

int abs (int x) {
  if (x < 0) return -x;
  return x;
}

void BFS () {
  pair <int, int> tempPair, anotherPair;
  int tempX, tempY;
  queue < pair <int, int> > myQueue;
  visited[startX][startY] = true;
  layer[startX][startY] = 0;
  tempPair.first = startX; tempPair.second = startY;
  myQueue.push(tempPair);

  while (! myQueue.empty()) {
    anotherPair = myQueue.front ();
    myQueue.pop ();
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++)
        if (abs(i) + abs(j) == 1) {
            tempX = i + anotherPair.first;
            tempY = j + anotherPair.second;
            if (tempX >= 0 && tempY >= 0 && tempX < n && tempY < m) {
              if (mall[tempX][tempY] != '#' && visited[tempX][tempY] == false) {
                visited[tempX][tempY] = true;
                layer[tempX][tempY] = layer[anotherPair.first][anotherPair.second] + 1;
                tempPair.first = tempX;
                tempPair.second = tempY;
                myQueue.push(tempPair);
              }
            }
        }
  }
}

int main () {
  int t;
  int finalRs, tempIntVal;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> mall[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        visited[i][j] = false;
        if (mall[i][j] == 'C') {
          startX = i;
          startY = j;
        }
      }
    BFS();
    finalRs = 0;
    tempIntVal = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (mall[i][j] == 'S') {
          finalRs += (layer[i][j] * 2);
          finalRs += 60;
          if (layer[i][j] > tempIntVal)
            tempIntVal = layer[i][j];
        }
    finalRs -= tempIntVal;
    cout << finalRs << "\n";
  }
}
