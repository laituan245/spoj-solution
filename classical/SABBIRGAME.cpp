// SABBIRGAME - Sabbir and Game
// http://www.spoj.com/problems/SABBIRGAME/

#include <iostream>
#define lli long long int
using namespace std;

lli min (lli a, lli b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int t, n;
    lli a, sum, tmp;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n;
        sum = 0; tmp = 1000000000000000;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            tmp = min(tmp, sum);
        }
        if (tmp > 0)
            cout << "0\n";
        else
            cout << (-tmp)+1 << "\n";
    }
}
