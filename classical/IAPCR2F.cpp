// IAPCR2F - Summer Trip
// http://www.spoj.com/problems/IAPCR2F/

#include <iostream>
#include <vector>
using namespace std;

int group_count;
int sum[1001];
int a[1001];
bool visited[1001];
vector <int> adjList[1001];

void DFS(int v) {
  visited[v] = true;
  sum[group_count] = sum[group_count] + a[v];
  for (int i = 0; i < adjList[v].size(); i++)
    if (!visited[adjList[v][i]])
      DFS(adjList[v][i]);
}

void quickSort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

int main () {
  int t;
  int n, m, u, v;
  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      adjList[i].clear();
      visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    group_count = 0;
    for (int i = 1; i <= n; i++)
      if (!visited[i]) {
        sum[group_count] = 0;
        DFS(i);
        group_count ++;
      }
    cout << "Case " << (z+1) << ": " << group_count << "\n";
    quickSort(sum, 0, group_count - 1);
    for (int i = 0; i < group_count; i++) {
      cout << sum[i];
      if (i < group_count - 1)
        cout << " ";
      else
        cout << "\n";
    }
  }
}
