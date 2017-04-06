// PLAYGAME - PLAYGAME
// http://www.spoj.com/problems/PLAYGAME/
#include <iostream>
#define ulli unsigned long long int
using namespace std;

int main() {
    int t;
    ulli n;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n;
        switch(n % 3) {
            case 0 : cout << "Ragini";
                     break;
            case 1 : cout << "Hemlata";
                     break;
            case 2 : cout << "Hemlata";
                     break;
        }
        cout << "\n";
    }
}
