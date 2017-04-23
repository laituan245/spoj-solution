// PRIME1 - Prime Generator
// http://www.spoj.com/problems/PRIME1/

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
#include <math.h>
#include <set>
using namespace std;

bool prime[35001];
vector<int> primesLessThan35000;

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

inline void inp( int &n ) {
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

bool isPrime(int n) {
    if (n <= 35000)
        return prime[n];
    int k = (int) sqrt((double) n);
    for (int i = 0; i < primesLessThan35000.size(); i++) {
        int u = primesLessThan35000[i];
        if (u > k)
            break;
        if (n % u == 0)
            return false;
    }
    return true;
}

int main() {
    SieveOfEratosthenes(35000);
    primesLessThan35000.clear();
    for (int i = 2; i <= 35000; i++) {
        if (prime[i]) {
            primesLessThan35000.push_back(i);
        }
    }
    int t, m, n;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(m); inp(n);
        for (int i = m; i <= n; i++) {
            if (isPrime(i)) {
                printf("%d\n", i);
            }
        }
        if (z != t-1)
            printf("\n");
    }
}
