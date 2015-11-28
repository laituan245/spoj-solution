// FURYROAD - Fury Road
// http://www.spoj.com/problems/FURYROAD/
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n;
int finalRs;
int x[10000];
int y[10000];
bool hasWarBoy[1001][1001];
bool visited[1001][1001];

void BFS (int sx, int sy) {
	queue <int> myQueueX;
	queue <int> myQueueY;
	visited[sx][sy] = true;
	myQueueX.push(sx);
	myQueueY.push(sy);
	while (!myQueueX.empty()) {
		int tX = myQueueX.front();
		int tY = myQueueY.front();
		myQueueX.pop(); myQueueY.pop();
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <=1; dy++) 
				if (!(dx == 0 && dy == 0))
				{
					int newX = tX + dx;
					int newY = tY + dy;
					if (newX >= 0 && newY >= 0 && newX < 1001 && newY < 1001) {
						if (hasWarBoy[newX][newY] && !visited[newX][newY]) {
							visited[newX][newY] = true;
							myQueueX.push(newX);
							myQueueY.push(newY);
						}
					}
				}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int z = 0; z < t; z++) {
		for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 1001; j++) {
				hasWarBoy[i][j] = false;
				visited[i][j] = false;
			}
			
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &x[i], &y[i]);
			hasWarBoy[x[i]][y[i]] = true;
		}
		
		finalRs = 0;
		for (int i = 0; i < n; i++)
			if (!visited[x[i]][y[i]]){
				finalRs += 1;
				BFS(x[i], y[i]);
			}	
			
		cout << "Case " << (z+1) << ": " << finalRs << "\n";
	}
}
