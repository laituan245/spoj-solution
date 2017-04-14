// ALCATRAZ2 - GO GOA GONE
// http://www.spoj.com/problems/ALCATRAZ2/

#include <iostream>
#include <vector>
using namespace std;

int m;
int a[8];
int assignment[8];
int finalAns = 0;
vector <int> Adjlist[8];

void backtrack(int n) {
    for (int i = 0; i < 2; i++) {
        assignment[n] = i;
        if (n == 7) {
            bool satisfied = true;
            for (int j = 0; j < 8; j++)
                if (assignment[j] == 1) {
                    for (int zz = 0; zz < Adjlist[j].size(); zz++)
                        if (assignment[Adjlist[j][zz]] == 1)
                            satisfied = false;
                }
            if (satisfied) {
                int tmp = 0;
                for (int j = 0; j < 8; j++)
                    if (assignment[j] == 1) {
                        tmp += a[j];
                    }
                if (tmp > finalAns)
                    finalAns = tmp;
            }
        } else
            backtrack(n+1);
        assignment[n] = 0;
    }
}

int main() {
    int tmpA, tmpB;
    for (int i = 0; i < 8; i++) {
        cin >> a[i];
        assignment[i] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmpA >> tmpB;
        Adjlist[tmpA-1].push_back(tmpB-1);
        Adjlist[tmpB-1].push_back(tmpA-1);
    }
    backtrack(0);
    cout << finalAns << "\n";
}
