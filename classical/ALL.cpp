// ALL - All Discs Considered
// www.spoj.com/problems/ALL
// laituanksa245

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int min (int a, int b) {
  if (a < b) return a;
  return b;
}

int max (int a, int b) {
  if (a > b) return a;
  return b;
}

int main () {
  int n1, n2, n, d;
  vector <int> adjList[100001];
  int inDegree[100001];
  bool considered[100001];
  queue <int> disc1Queue;
  queue <int> disc2Queue;
  int tempX, tempY, tempCurDisc, tempCount;
  int finalRs = 100000000;
  while (true) {
    scanf ("%d %d %d", &n1, &n2, &d);
    if (n1 == 0 && n2 == 0 && d == 0)
      break;
    finalRs = 100000000;
    n = n1 + n2;
    for (int i = 1; i <= n; i++) {
      adjList[i].clear();
      inDegree[i] = 0;
    }
    for (int z = 0; z < d; z++) {
      scanf ("%d %d", &tempX, &tempY);
      adjList[tempY].push_back(tempX);
      inDegree[tempX]++;
    }

    while (!disc1Queue.empty()) disc1Queue.pop ();
    while (!disc2Queue.empty()) disc2Queue.pop ();

    for (int i = 1; i <= n; i++) {
      considered[i] = false;
      if (inDegree[i] == 0)
      {
        if (i <= n1)
          disc1Queue.push(i);
        else
          disc2Queue.push(i);
      }
    }

    if (!disc1Queue.empty()) {
      tempCount = 0;
      tempCurDisc = 1;
      while (!disc1Queue.empty() || !disc2Queue.empty()) {
        if (tempCurDisc == 1 && disc1Queue.empty()) {
          tempCount ++;
          tempCurDisc = 2;
        }
        else
        if (tempCurDisc == 2 && disc2Queue.empty()) {
          tempCount ++;
          tempCurDisc = 1;
        }
        int u;
        if (tempCurDisc == 1) {
          u = disc1Queue.front ();
          disc1Queue.pop();
        }
        else {
          u = disc2Queue.front ();
          disc2Queue.pop();
        }
        considered[u] = true;
        for (int i = 0; i < adjList[u].size(); i++)
          if (considered[adjList[u][i]] == false) {
            inDegree[adjList[u][i]] -= 1;
            if (inDegree[adjList[u][i]] == 0) {
              if (adjList[u][i] <= n1)
                disc1Queue.push(adjList[u][i]);
              else
                disc2Queue.push(adjList[u][i]);
            }
          }
      }
      finalRs = min (finalRs, tempCount);
    }

    while (!disc1Queue.empty()) disc1Queue.pop ();
    while (!disc2Queue.empty()) disc2Queue.pop ();
    for (int i = 1; i <= n; i++) {
      considered[i] = false;
      inDegree[i] = 0;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < adjList[i].size(); j++)
        inDegree[adjList[i][j]] ++;
    for (int i = 1; i <= n; i++) {
      if (inDegree[i] == 0)
      {
        if (i <= n1)
          disc1Queue.push(i);
        else
          disc2Queue.push(i);
      }
    }

    // Duplicated code (But I am too lazy to do anything about it)


    if (!disc2Queue.empty()) {
      tempCount = 0;
      tempCurDisc = 2;
      while (!disc1Queue.empty() || !disc2Queue.empty()) {
        if (tempCurDisc == 1 && disc1Queue.empty()) {
          tempCount ++;
          tempCurDisc = 2;
        }
        else if (tempCurDisc == 2 && disc2Queue.empty()) {
          tempCount ++;
          tempCurDisc = 1;
        }
        int u;
        if (tempCurDisc == 1) {
          u = disc1Queue.front ();
          disc1Queue.pop();
        }
        else {
          u = disc2Queue.front ();
          disc2Queue.pop();
        }
        considered[u] = true;
        for (int i = 0; i < adjList[u].size(); i++)
          if (considered[adjList[u][i]] == false) {
            inDegree[adjList[u][i]] -= 1;
            if (inDegree[adjList[u][i]] == 0) {
              if (adjList[u][i] <= n1)
                disc1Queue.push(adjList[u][i]);
              else
                disc2Queue.push(adjList[u][i]);
            }
        }
      }
      finalRs = min(finalRs, tempCount);
    }
    cout << finalRs + 2 << "\n";
  }
}
