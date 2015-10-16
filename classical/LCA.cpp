// LCA - Lowest Common Ancestor
// http://www.spoj.com/problems/LCA/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int n, rootnb;
vector <int> myChildren[1001];
unordered_map <int, bool> notRoot;
int layer[1001];
int pre[1001];
bool visited[1001];

void BFS (int s) {
  visited[s] = true;
  layer[s] = 0;
  queue <int> myQueue;
  myQueue.push(s);
  while (!myQueue.empty()) {
    int u = myQueue.front();
    myQueue.pop ();
    for (int i = 0; i < myChildren[u].size(); i++)
      if (visited[myChildren[u][i]] == false) {
        visited[myChildren[u][i]] = true;
        layer[myChildren[u][i]] = layer[u] + 1;
        pre[myChildren[u][i]] = u;
        myQueue.push (myChildren[u][i]);
      }
  }
}

int lca (int a, int b) {
  int node1, node2;
  if (layer[a] > layer[b]) {
    node1 = a; node2 = b;
  }
  else {
    node1 = b; node2 = a;
  }

  while (layer[node1] > layer[node2])
    node1 = pre[node1];
  while (node1 != node2) {
    node1 = pre[node1];
    node2 = pre[node2];
  }
  return node1;
}

int main () {
  int m, temp, t;
  scanf ("%d", &t);
  for (int z = 0; z < t; z++) {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
      myChildren[i].clear();
    for (int i = 1; i <= n; i++) {
      layer[i] = 0;
      pre[i] = -1;
      visited[i] = false;
      scanf ("%d", &m);
      for (int j = 0; j < m; j++) {
        scanf ("%d", &temp);
        myChildren[i].push_back (temp);
        notRoot[temp] = true;
      }
    }

    for (int i = 1; i <= n; i++)
      if (!notRoot[i]) {
        rootnb = i;
        break;
      }

    BFS(rootnb);

    printf ("Case %d:\n", (z+1));
    int q, a ,b;
    cin >> q;
    for (int qnb = 0; qnb < q; qnb++) {
      cin >> a >> b;
      cout << lca (a,b) << "\n";
    }
  }
}
