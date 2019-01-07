// SKS001 - Secret Recipe
// https://www.spoj.com/problems/SKS001/

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
#include<unordered_map>
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

bool prime[44725];
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

bool is_prime(int n) {
    int k = (int) ceil(sqrt(n));
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 0; i < prime_nbs.size(); i++) {
        if (prime_nbs[i] > k) break;
        if (n % prime_nbs[i] == 0) return false;
    }
    return true;
}

int main() {
    SieveOfEratosthenes(44724);
    for (int i = 2; i < 44725; i++)
        if (prime[i]) prime_nbs.push_back(i);

    int a, b;
    inp(a); inp(b);
    if (a == b) cout << 0 << "\n";
    else {
        unsigned long long int result = 0;
        for (int i = b; i > a; i--) {
            result += ((unsigned long long int) i);
            if (is_prime(i)) {
                break;
            }
        }
        cout << result << "\n";
    }
}
