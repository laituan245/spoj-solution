// BGIRL - Beautiful Girl
// https://www.spoj.com/problems/BGIRL/

#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include<set>
#include<math.h>
using namespace std;

inline void inp( int &n ) {
  n=0;
  int ch=getchar_unlocked();int sign=1;
  while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
  while(ch >= '0' && ch <= '9' )
         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  n=n*sign;
}

int n, m; // Nb of boys and Nb of relations respectively
vector<int> adjList[100001];
bool visited[100001];

bool is_prime(int nb) {
    if (nb < 2) return false;
    if (nb == 2 || nb == 3) return true;
    int k = (int) sqrt(nb);
    for (int i = 2; i <= k; i++)
        if (nb % i == 0) return false;
    return true;
}

int BFS(int v) {
    int result = 0;

    // Initialize a queue
    queue<int> my_queue;
    while (!my_queue.empty())
        my_queue.pop();


    my_queue.push(v);
    visited[v] = true;

    while (!my_queue.empty()) {
        int u = my_queue.front();
        my_queue.pop();
        result += 1;
        for (int i = 0; i < adjList[u].size(); i++)
            if (!visited[adjList[u][i]]) {
                visited[adjList[u][i]] = true;
                my_queue.push(adjList[u][i]);
            }
    }

    return result;
}

int main() {
    int t; // Nb of test cases
    int a, b, cc_size, final_ans;
    inp(t);
    for (int zz = 0; zz < t; zz ++) {
        inp(n); inp(m);
        for (int i = 1; i <= n; i++) {
            adjList[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < m; i++) {
            inp(a); inp(b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        final_ans = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cc_size = BFS(i);
                if (is_prime(cc_size) && cc_size > final_ans)
                    final_ans = cc_size;
            }
        }
        cout << final_ans << "\n";
    }
}
