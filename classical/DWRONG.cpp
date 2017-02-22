// DWRONG - Do It Wrong, Get It Right
// http://www.spoj.com/problems/DWRONG/

#include <iostream>
#include <stdio.h>
#include <vector>
#define ulli unsigned long long int
using namespace std;

vector <ulli> a_results;
vector <ulli> m_results;

bool isLessThan(int idx_1, int idx_2) {
    ulli a1 = a_results[idx_1]; ulli m1 = m_results[idx_1];
    ulli a2 = a_results[idx_2]; ulli m2 = m_results[idx_2];
    ulli prod1 = a1 * m2; ulli prod2 = a2 * m1;
    if (prod1 < prod2)
        return true;
    if (prod1 == prod2 && a1 < a2)
        return true;
    return false;
}

void quickSort(int left, int right) {
      int i = left, j = right;
      ulli tmp;
      int pivot_idx = (left + right) / 2;

      /* partition */
      while (i <= j) {
            while (isLessThan(i, pivot_idx))
                  i++;
            while (isLessThan(pivot_idx, j))
                  j--;
            if (i <= j) {
                  tmp = a_results[i];
                  a_results[i] = a_results[j];
                  a_results[j] = tmp;
                  tmp = m_results[i];
                  m_results[i] = m_results[j];
                  m_results[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(left, j);
      if (i < right)
            quickSort(i, right);
}

int main() {
    int nb_ans;
    ulli b, n, two_n, n_squared;
    ulli tmp_numerator;
    ulli tmp_denominator;
    while (true) {
        cin >> b >> n;
        two_n = 2 * n;
        n_squared = n * n;
        nb_ans = 0;
        a_results.clear(); m_results.clear();
        if (b == 0 && n == 0)
            break;
        for (ulli tmp_m = 1; tmp_m <= two_n; tmp_m ++) {
            if (tmp_m != n) {
                tmp_numerator = b * tmp_m * (two_n - tmp_m);
                tmp_denominator = n_squared;
                if (tmp_numerator % tmp_denominator == 0) {
                    m_results.push_back(tmp_m);
                    a_results.push_back(tmp_numerator / tmp_denominator);
                    nb_ans += 1;
                }
            }
        }
        quickSort(0, nb_ans-1);
        for (int i = 0; i < nb_ans; i++) {
            cout << a_results[i] << "/" << m_results[i];
            if (i < nb_ans-1)
                cout << " ";
        }
        cout << "\n";
    }
}
