// DIEHARD - DIE HARD
// http://www.spoj.com/problems/DIEHARD/

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
#include <math.h>
using namespace std;

inline void inp( int &n ) {
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

int main() {
    int t, h, a, finalRs;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(h); inp(a);
        finalRs = 0;
        for (int nb_fires = 0; nb_fires < 1000; nb_fires ++) {
            int tmp_health = h - 17 * nb_fires;
            int tmp_armor = a + 7 * nb_fires;
            int tmp_steps = 2 * nb_fires;
            if (tmp_health <= 0) {
                finalRs = max(finalRs, tmp_steps - 1);
                break;
            }
            int tmp_A = (int) ceil(((double) tmp_health) / 2.0);
            int tmp_B = (int) ceil(((double) tmp_armor) / 8.0);
            int tmp = min(tmp_A, tmp_B);
            tmp_steps += (2 * tmp - 1);
            finalRs = max(finalRs, tmp_steps);
        }
        cout << finalRs << "\n";
    }
}
