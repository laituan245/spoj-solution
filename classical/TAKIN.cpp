// TAKIN - Taskin and apple tree
// http://www.spoj.com/problems/TAKIN/

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
#include <unordered_map>

#define ulli unsigned long long int

using namespace std;

int t, n;
ulli m;
ulli a[20];
ulli dp[(1 << 20) + 1];
ulli final_ans;

int main() {
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ulli nb_cases = (1 << n);
        final_ans = 0;
        dp[0] = 0;
        for (ulli i = 1; i < nb_cases; i++) {
            int count = -1;
            ulli tmp = i;
            while (tmp != 0) {
                count = count + 1;
                tmp = tmp >> 1;
            }
            dp[i] = dp[i ^ (1 << count)] + a[count];
            if (dp[i] <= m && dp[i] > final_ans)
                final_ans = dp[i];
        }

        cout << final_ans << "\n";

    }
}
