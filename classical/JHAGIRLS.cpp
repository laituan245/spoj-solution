// http://www.spoj.com/problems/JHAGIRLS/
// This is more or less the eight queens puzzle (https://en.wikipedia.org/wiki/Eight_queens_puzzle)

#include <iostream>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n;
        switch(n) {
            case 4 : cout << "1 2\n2 4\n3 1\n4 3\n";
                     break;
            case 5 : cout << "1 1\n2 3\n3 5\n4 2\n5 4\n";
                     break;
            case 6: cout << "1 2\n2 4\n3 6\n4 1\n5 3\n6 5\n";
                     break;
                     case 7: cout << "1 1\n2 3\n3 5\n4 7\n5 2\n6 4\n7 6\n";
                                          break;
                     case 8: cout << "1 1\n2 5\n3 8\n4 6\n5 3\n6 7\n7 2\n8 4\n";
                                          break;
                     case 9: cout << "1 1\n2 3\n3 6\n4 8\n5 2\n6 4\n7 9\n8 7\n9 5\n";
                                          break;
                     case 10: cout << "1 1\n2 3\n3 6\n4 8\n5 10\n6 5\n7 9\n8 2\n9 4\n10 7\n";
                                          break;
                     case 11: cout << "1 1\n2 3\n3 5\n4 7\n5 9\n6 11\n7 2\n8 4\n9 6\n10 8\n11 10\n";
                                          break;
                     case 12: cout << "1 1\n2 3\n3 5\n4 8\n5 10\n6 12\n7 6\n8 11\n9 2\n10 7\n11 9\n12 4\n";
                                          break;
                     case 13: cout << "1 1\n2 3\n3 5\n4 2\n5 9\n6 12\n7 10\n8 13\n9 4\n10 6\n11 8\n12 11\n13 7\n";
                                          break;
                     case 14: cout << "1 1\n2 3\n3 5\n4 7\n5 12\n6 10\n7 13\n8 4\n9 14\n10 9\n11 2\n12 6\n13 8\n14 11\n";
                                          break;
                     case 15: cout << "1 1\n2 3\n3 5\n4 2\n5 10\n6 12\n7 14\n8 4\n9 13\n10 9\n11 6\n12 15\n13 7\n14 11\n15 8\n";
                                          break;
                     case 16: cout << "1 1\n2 3\n3 5\n4 2\n5 13\n6 9\n7 14\n8 12\n9 15\n10 6\n11 16\n12 7\n13 4\n14 11\n15 8\n16 10\n";
                                          break;
                     case 17: cout << "1 1\n2 3\n3 5\n4 2\n5 8\n6 11\n7 15\n8 7\n9 16\n10 14\n11 17\n12 4\n13 6\n14 9\n15 12\n16 10\n17 13\n";
                                          break;
                     case 18: cout << "1 1\n2 3\n3 5\n4 2\n5 8\n6 15\n7 12\n8 16\n9 13\n10 17\n11 6\n12 18\n13 7\n14 4\n15 11\n16 9\n17 14\n18 10\n";
                                          break;
                     case 19: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 13\n8 15\n9 17\n10 19\n11 7\n12 16\n13 18\n14 11\n15 6\n16 8\n17 10\n18 12\n19 14\n";
                                          break;
                     case 20: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 13\n7 15\n8 12\n9 18\n10 20\n11 17\n12 9\n13 16\n14 19\n15 8\n16 10\n17 7\n18 14\n19 6\n20 11\n";
                                          break;
                     case 21: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 15\n9 21\n10 18\n11 20\n12 17\n13 19\n14 7\n15 12\n16 10\n17 8\n18 6\n19 14\n20 16\n21 13\n";
                                          break;
                     case 22: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 10\n7 14\n8 17\n9 20\n10 13\n11 19\n12 22\n13 18\n14 8\n15 21\n16 12\n17 9\n18 6\n19 16\n20 7\n21 11\n22 15\n";
                                          break;
                     case 23: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 18\n10 20\n11 22\n12 19\n13 21\n14 10\n15 8\n16 6\n17 23\n18 7\n19 16\n20 12\n21 15\n22 17\n23 14\n";
                                          break;
                     case 24: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 14\n9 18\n10 22\n11 19\n12 23\n13 20\n14 24\n15 10\n16 21\n17 6\n18 8\n19 12\n20 16\n21 13\n22 7\n23 17\n24 15\n";
                                          break;
                     case 25: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 19\n11 21\n12 24\n13 20\n14 25\n15 23\n16 6\n17 8\n18 10\n19 7\n20 14\n21 16\n22 18\n23 12\n24 17\n25 22\n";
                                          break;
                     case 26: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 21\n11 23\n12 25\n13 20\n14 22\n15 24\n16 26\n17 10\n18 7\n19 16\n20 12\n21 8\n22 6\n23 18\n24 14\n25 19\n26 17\n";
                                          break;
                     case 27: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 17\n11 19\n12 23\n13 25\n14 27\n15 24\n16 26\n17 6\n18 10\n19 7\n20 16\n21 8\n22 12\n23 14\n24 21\n25 18\n26 20\n27 22\n";
                                          break;
                     case 28: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 17\n11 23\n12 25\n13 22\n14 28\n15 26\n16 24\n17 27\n18 7\n19 12\n20 16\n21 18\n22 8\n23 10\n24 14\n25 20\n26 6\n27 21\n28 19\n";
                                          break;
                     case 29: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 6\n11 20\n12 24\n13 26\n14 21\n15 29\n16 27\n17 25\n18 28\n19 8\n20 12\n21 7\n22 16\n23 10\n24 17\n25 22\n26 14\n27 18\n28 23\n29 19\n";
                                          break;
                     case 30: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 7\n11 23\n12 26\n13 28\n14 25\n15 22\n16 24\n17 30\n18 27\n19 29\n20 16\n21 12\n22 10\n23 8\n24 6\n25 18\n26 20\n27 17\n28 14\n29 21\n30 19\n";
                                          break;
                     case 31: cout << "1 1\n2 3\n3 5\n4 2\n5 4\n6 9\n7 11\n8 13\n9 15\n10 6\n11 18\n12 23\n13 26\n14 28\n15 31\n16 25\n17 27\n18 30\n19 7\n20 17\n21 29\n22 14\n23 10\n24 8\n25 20\n26 12\n27 16\n28 19\n29 22\n30 24\n31 21\n";
                                          break;
        }
    }
}
