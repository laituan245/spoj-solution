// CHUNK2 - Popatlal ki shaadi
// https://www.spoj.com/problems/CHUNK2/

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

bool prime[2000001];
vector <int> prime_nbs;
void SieveOfEratosthenes(int n)
{
    prime[0] = false; prime[1] = false;
    for (int i=2; i <= n; i++)
        prime[i] = true;
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int n, m; // Nb of girls and Nb of relations respectively
vector<int> adjList[100001];
bool visited[100001];

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
    SieveOfEratosthenes(2000000);
    for (int i = 2; i < 2000000; i++)
        if (prime[i])
            prime_nbs.push_back(i);

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
        if (m == 0) {
            cout << "-1\n";
            continue;
        }
        final_ans = 1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cc_size = BFS(i);
                if (cc_size > final_ans)
                    final_ans = cc_size;
            }
        }
        cout << prime_nbs[final_ans-1] << "\n";
    }
}
