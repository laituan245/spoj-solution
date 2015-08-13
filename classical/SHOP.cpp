// SHOP - Shopping
// http://www.spoj.com/problems/SHOP/
// laituanksa245

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAX_VAL = 1000000;

struct PQelement {
  int x;
  int y;
  int dist;
};

class ComparePQelement {
public:
    bool operator()(PQelement& e1, PQelement& e2)
    {
       if (e2.dist < e1.dist) return true;
       return false;
    }
};

int charToInt (char aChar) {
  if (aChar == 'S' || aChar == 'D') return 0; // For this particular problem
  string tmpStr = "0123456789";
  int rsIndex = 0;
  while (aChar != tmpStr[rsIndex])
    rsIndex++;
  return rsIndex;
}

int main (){
  int m, n;
  int startingX, startingY, destX, destY, tempX, tempY;
  PQelement tempElement, anotherTempElement;
  string shopstate[25];
  int dist[25][25];
  while (true) {
    priority_queue <PQelement, vector<PQelement>, ComparePQelement> myPQ;
    cin >> m >> n;
    if (m == 0 && n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> shopstate[i];

    // Some initialization steps
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        dist[i][j] = MAX_VAL;
        if (shopstate[i][j] == 'S') {
          startingX = i;
          startingY = j;
        }
        else if (shopstate[i][j] == 'D') {
          destX = i;
          destY = j;
        }
      }

    // Let's simply use Dijkstra's algorithm
    dist[startingX][startingY] = 0;
    tempElement.x = startingX; tempElement.y = startingY; tempElement.dist = 0;
    myPQ.push(tempElement);

    while (!myPQ.empty()) {
        tempElement = myPQ.top ();
        myPQ.pop ();
        while (tempElement.dist != dist[tempElement.x][tempElement.y]) {
          tempElement = myPQ.top ();
          myPQ.pop ();
        }

        for (int i = -1; i <= 1; i++) {
          tempX = tempElement.x + i;
          tempY = tempElement.y;
          if (tempX >= 0 && tempX < n && shopstate[tempX][tempY] != 'X' && dist[tempX][tempY] > dist[tempElement.x][tempElement.y] + charToInt(shopstate[tempX][tempY])) {
                dist[tempX][tempY] = dist[tempElement.x][tempElement.y] + charToInt(shopstate[tempX][tempY]);
                anotherTempElement.x = tempX;
                anotherTempElement.y = tempY;
                anotherTempElement.dist = dist[tempX][tempY];
                myPQ.push (anotherTempElement);
          }

          tempX = tempElement.x;
          tempY = tempElement.y + i;
          if (tempY >= 0 && tempY < m && shopstate[tempX][tempY] != 'X' && dist[tempX][tempY] > dist[tempElement.x][tempElement.y] + charToInt(shopstate[tempX][tempY])) {
                dist[tempX][tempY] = dist[tempElement.x][tempElement.y] + charToInt(shopstate[tempX][tempY]);
                anotherTempElement.x = tempX;
                anotherTempElement.y = tempY;
                anotherTempElement.dist = dist[tempX][tempY];
                myPQ.push (anotherTempElement);
          }
        }
    }

    cout << dist[destX][destY] << "\n";
  }
}
