// UOFTCG - Office Mates
// http://www.spoj.com/problems/UOFTCG/

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
#include <unordered_map>
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

int n, m, totalNbSequences;
vector <int> adjList[100001];
vector <int> nodes;
unordered_map <int, bool> isSpecial;
unordered_map <int, bool> hasParent;
bool visited[100001];

void BFS(int startVertex) {
    queue <int> myqueue;
    myqueue.push(startVertex);
    visited[startVertex] = true;
    while (!myqueue.empty()) {
        int u = myqueue.front();
        myqueue.pop();
        nodes.push_back(u);
        isSpecial[u] = false;
        for (int i = 0; i < adjList[u].size(); i++) {
            if (!visited[adjList[u][i]]) {
                myqueue.push(adjList[u][i]);
                visited[adjList[u][i]] = true;
                hasParent[adjList[u][i]] = true;
            }
        }
    }
}

int calculateNbSequeces() {
    unordered_map <int, bool> seen;
    int tmp_count;
    int rs = 0;
    for (int i = nodes.size()-1; i >= 0; i--) {
        tmp_count = 0;
        for (int j = 0; j < adjList[nodes[i]].size(); j++) {
            int u = adjList[nodes[i]][j];
            if (!isSpecial[u] && seen[u])
                tmp_count ++;
        }

        if (tmp_count <= 1 && hasParent[nodes[i]] == false) {
            rs += 1;
            isSpecial[nodes[i]] = true;
        }
        if (tmp_count > 1) {
            rs += (tmp_count - 1);
            isSpecial[nodes[i]] = true;
        }
        seen[nodes[i]] = true;
    }
    return rs;
}

int main() {
    int t;  // Nb of test cases
    int a, b;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(n); inp(m);
        for (int i = 1; i <= n; i++) {
            adjList[i].clear();
            visited[i] = false;
            totalNbSequences = 0;
        }
        for (int j = 0; j < m; j++) {
            inp(a); inp(b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                nodes.clear();
                isSpecial.clear();
                hasParent.clear();
                BFS(i);
                totalNbSequences += calculateNbSequeces();
            }
        }
        cout << (n+(totalNbSequences-1)) << "\n";
    }
}
