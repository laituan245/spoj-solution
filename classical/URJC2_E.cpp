// URJC2_E - Stressful Activities
// http://www.spoj.com/problems/URJC2_E/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <stdio.h>
#include <set>
using namespace std;

inline void inp( int &n ) {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int k, h, n;
int sum[100][50000];

int main() {
    int t, tmp, q, a, b, rs1, rs2;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(k); inp(h); inp(n);
        for (int i = 0; i < k; i++) {
            sum[i][0] = 0;
            for (int j = 1; j <= n; j++) {
                inp(tmp);
                sum[i][j] = sum[i][j-1] + tmp;
            }
        }
        inp(q);
        for (int zz = 0; zz < q; zz++) {
            inp(a); inp(b);
            rs1 = 0;
            for (int i = 0; i < k; i++)
                if (sum[i][b] - sum[i][a-1] <= h)
                    rs1++;
            rs2 = k - rs1;
            cout << rs2 << " - " << rs1 << "\n";
        }
    }
}
