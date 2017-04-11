// HPPROF - Help Professor
// http://www.spoj.com/problems/HPPROF/

#include <iostream>
#include <string>
#define ulli unsigned long long int
using namespace std;

int charToInt (string c) {
    if (c == "0") return 0;
    if (c == "1") return 1;
    if (c == "2") return 2;
    if (c == "3") return 3;
    if (c == "4") return 4;
    if (c == "5") return 5;
    if (c == "6") return 6;
    if (c == "7") return 7;
    if (c == "8") return 8;
    return 9;
}


int main() {
    string str;
    ulli tmp1, tmp2, tmp;
    cin >> str;
    if (str.length() == 1)
        cout << "1\n";
    else {
        tmp1 = 1; tmp2 = 1;
        for (int i = 1; i < str.length(); i++) {
            tmp = tmp2;
            int nb = charToInt(str.substr(i-1,1)) * 10 + charToInt(str.substr(i,1));
            if (nb >= 10 && nb <= 20)
                tmp2 = tmp1 + tmp2;
            else
                tmp2 = tmp2;
            tmp1 = tmp;
        }
    }
    cout << tmp2 << "\n";
}
