// ADADUNG - Ada and Manure
// http://www.spoj.com/problems/ADADUNG/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#define ulli unsigned long long int
using namespace std;

int t, n;
ulli rs[10000001];

// Fast input
inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

// Dynamic programming
void dp() {
    ulli tmp = 1;
    rs[1] = 0;
    rs[2] = 1;
    rs[3] = 2;
    for (int i = 4; i < 10000001; i++) {
        rs[i] = (rs[i-1] * i + tmp) % 1000000007;
        tmp = tmp * (-1);
    }
}

int main() {
    dp();
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(n);
        cout << rs[n] << "\n";
    }
}
