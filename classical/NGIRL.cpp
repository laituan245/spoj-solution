// NGIRL - Namit In Trouble
// http://www.spoj.com/problems/NGIRL/
// laituanksa245

#include <iostream>
#include <stdio.h>
#include <math.h>
#define ulli unsigned long long int
using namespace std;

bool prime[100001];

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

int main() {
    // Some preprocessing
    SieveOfEratosthenes(100000);
    int tmp_arr[100001];
    int rs1_lookup[100001];
    tmp_arr[2] = 2;
    rs1_lookup[2] = 1;
    int last_prime = 2, nb_primes = 1;
    for (int i = 3; i < 100001; i++) {
        if (prime[i]) {
            last_prime = i;
            nb_primes++;
        }
        tmp_arr[i] = last_prime;
        rs1_lookup[i] = nb_primes;
    }

    int t;
    ulli n, k;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> k;
        if (n < 4) {
            cout << "0 0\n";
        } else {
            int firstRs, secondRs;
            int tmp_sqrt = (int) sqrt((double) n);
            firstRs = rs1_lookup[tmp_sqrt];
            tmp_sqrt = (int) sqrt((double) k);
            secondRs = firstRs - rs1_lookup[tmp_sqrt];
            if (k > n)
                secondRs = 0;
            cout << firstRs << " " << secondRs << "\n";
        }
    }
}
