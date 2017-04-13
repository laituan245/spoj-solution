// INCARDS - Invitation Cards
// http://www.spoj.com/problems/INCARDS/
#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include <set>
#include <utility>
#define INF 2000000000
using namespace std;

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

class Compare
{
public:
    bool operator() (pair <int, int> p1, pair <int, int> p2) {
        return p1.second >= p2.second;
    }
};

int n, m;
vector < pair <int, int> > AdjList[1000001];
vector < pair <int, int> > ReversedAdjList[1000001];
priority_queue < pair <int, int>, vector < pair <int, int> >, Compare> pq;
int dist[1000001];
bool calculated[1000001];

void dijkstra1(vector < pair <int, int> > MyAdjList[]) {
    int count = 0;
    pair <int, int> tmpPair;
    dist[1] = 0; calculated[1] = false;
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
        calculated[i] = false;
    }
    tmpPair.first = 1; tmpPair.second = dist[1];
    pq.push(tmpPair);
    while (count < n) {
        tmpPair = pq.top();
        pq.pop();
        if (!calculated[tmpPair.first]) {
            count++;
            calculated[tmpPair.first] = true;
            int u = tmpPair.first;
            for (int i = 0; i < MyAdjList[u].size(); i++) {
                int v = MyAdjList[u][i].first;
                int edgeDist = MyAdjList[u][i].second;
                if (!calculated[v] && dist[v] > dist[u] + edgeDist) {
                    dist[v] = dist[u] + edgeDist;
                    tmpPair.first = v; tmpPair.second = dist[v];
                    pq.push(tmpPair);
                }
            }
        }
    }
    while (!pq.empty())
        pq.pop();
}


int main() {
    int t, tmpStart, tmpEnd, tmpPrice, finalRs;
    pair <int, int> tmpPair;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(n); inp(m);
        for (int i = 1; i <= n; i++) {
            AdjList[i].clear();
            ReversedAdjList[i].clear();
        }
        for (int j = 0; j < m; j++) {
            inp(tmpStart); inp(tmpEnd); inp(tmpPrice);
            // Add the normal edge
            tmpPair.first = tmpEnd; tmpPair.second = tmpPrice;
            AdjList[tmpStart].push_back(tmpPair);
            // Add the reversed edge
            tmpPair.first = tmpStart; tmpPair.second = tmpPrice;
            ReversedAdjList[tmpEnd].push_back(tmpPair);
        }
        finalRs = 0;
        dijkstra1(AdjList);
        for (int i = 2; i <= n; i++)
            finalRs += dist[i];
        dijkstra1(ReversedAdjList);
        for (int i = 2; i <= n; i++)
            finalRs += dist[i];
        printf("%d\n", finalRs);
    }
}
