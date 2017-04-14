// HAMSTER1 - Hamster flight
// http://www.spoj.com/problems/HAMSTER1/
#include <math.h>
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

double score(double angle, double v0, double k1, double k2) {
    return v0 * v0 * (2.0 * k1 * sin(angle) * cos(angle) + 0.5 * k2 * sin(angle) * sin(angle)) * 0.1;
}

int main() {
    cout << fixed;
    cout << setprecision(3);
    int t, tmp_v0, tmp_k1, tmp_k2;
    double v0, k1, k2;
    double possible_ans1, possible_ans2, score_1, score_2;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(tmp_v0); inp(tmp_k1); inp(tmp_k2);
        v0 = (double) tmp_v0; k1 = (double) tmp_k1; k2 = (double) tmp_k2;
        possible_ans1 = M_PI/4;
        score_1 = score(possible_ans1, v0, k1, k2);
        if (k2 > 0) {
            possible_ans2 = atan(-4 * k1 / k2);
            if (possible_ans2 <= 0)
                possible_ans2 += M_PI;
            possible_ans2 = possible_ans2 / 2;
            score_2 = score(possible_ans2, v0, k1, k2);
            if (score_2 > score_1)
                cout << possible_ans2 << " " << score_2 << "\n";
            else
                cout << possible_ans1 << " " << score_1 << "\n";
        } else {
            cout << possible_ans1 << " " << score_1 << "\n";
        }
    }
}
