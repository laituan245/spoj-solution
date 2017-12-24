// ADAGAME4 - Ada and Game of Divisors
// http://www.spoj.com/problems/ADAGAME4/

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
#include<math.h>
#include<cassert>
#include<stdio.h>
#include <set>
#define ulli unsigned long long int
#define MAX 20000001
using namespace std;

bool prime[MAX];
int nb_divisors[MAX];
int remain[MAX];
bool first_win[MAX];

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

void SieveOfEratosthenes(int n)
{
    prime[0] = false; prime[1] = false;
    nb_divisors[1] = 1;
    for (int i=2; i <= n; i++) {
        prime[i] = true;
        nb_divisors[i] = 1;
        remain[i] = i;
    }
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            nb_divisors[p] = 2;
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p) {
                prime[i] = false;
                int count = 1;
                int tmp = remain[i] / p;
                while (tmp % p == 0) {
                    tmp = tmp / p;
                    count++;
                }
                remain[i] = tmp;
                nb_divisors[i] *= (count+1);
            }
        }
    }
}

int get_nb_divisors(int n) {
    int result = 0;
    int k = (int) sqrt(n);
    for (int i = 1; i <= k; i++)
        if (n % i == 0) {
            result += 1;
            if (i * i != n)
                result += 1;
        }
    return result;
}

int main() {
    SieveOfEratosthenes(MAX-1);
    for (int i = 3; i < MAX; i++) {
        if (remain[i] != 1 && prime[i] == false)
            nb_divisors[i] *= 2;
        if (prime[i])
            nb_divisors[i] = 2;
    }

    first_win[1] = true;
    first_win[2] = true;
    first_win[3] = false;
    int last_index = 3;
    for (int i = 4; i < MAX; i++) {
        first_win[i] = false;
        if (i - last_index <= nb_divisors[i])
            first_win[i] = true;
        if (first_win[i] == false)
            last_index = i;
    }
    int t, n;
    inp(t);
    for (int z = 0; z < t; z++) {
        inp(n);
        if (first_win[n])
            printf("Ada\n");
        else
            printf("Vinit\n");
    }
}
