// BROW - A place for the brewery
// http://www.spoj.com/problems/BROW/

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
#define lli long long int
using namespace std;

lli t, n, total_length, total_demand, first_index, start_index, next_index;
lli demand[10000];
lli distance_to_next[10000];
lli left_distance_from_first[10000];
lli cum_demand[10000];
lli cost_left, cost_right, final_rs;

lli min(lli a, lli b) {
  return a < b ? a : b;
}

lli get_demand(lli a, lli b) {
  if (a > b) {
    return (total_demand - get_demand(b+1, a-1));
  }
  if (a == 0) return cum_demand[b];
  return cum_demand[b] - cum_demand[a-1];
}

int main() {
  cin >> t; // Nb of test cases
  for (lli z = 0; z < t; z++) {
    cin >> n; // Nb of cities
    total_length = 0; total_demand = 0;
    left_distance_from_first[0] = 0;
    for (lli i = 0; i < n; i++) {
      cin >> demand[i];
      cin >> distance_to_next[i];
      total_length += distance_to_next[i];
      total_demand += demand[i];
      if (i < n-1)
        left_distance_from_first[i+1] = left_distance_from_first[i] + distance_to_next[i];
      if (i == 0) cum_demand[i] = demand[i];
      else cum_demand[i] = cum_demand[i-1] + demand[i];
    }
    first_index = 0;
    for (lli i = 1; i < n; i++) {
      lli right_distance_from_first = total_length - left_distance_from_first[i];
      if (left_distance_from_first[i] > right_distance_from_first) {
        first_index = i - 1;
        break;
      }
    }

    // First iteration
    cost_left = 0; cost_right = 0;
    for (lli i = 1; i < n; i++) {
      lli right_distance_from_first = total_length - left_distance_from_first[i];
      if (i <= first_index) cost_left += demand[i] * left_distance_from_first[i];
      if (i > first_index) cost_right += demand[i] * right_distance_from_first;
    }
    final_rs = cost_left + cost_right;

    // Other iterations
    start_index = first_index;
    for (lli i = 1; i < n; i++) {
      lli moved_dist = left_distance_from_first[i] - left_distance_from_first[i-1];
      if (start_index == i - 1) {
        start_index = i;
        cost_left = 0;
        cost_right += (moved_dist * total_demand);
        cost_right -= (demand[i] * total_length);
      } else {
        cost_left -= (moved_dist * get_demand(i, start_index));
        cost_right += (moved_dist * (total_demand - get_demand(i, start_index)));
      }
      while(true) {
        next_index = (start_index + 1) % n;
        if (next_index == i) break;
        lli left_distance;
        if (next_index > i) {
          left_distance = left_distance_from_first[next_index] - left_distance_from_first[i];
        }
        else {
          left_distance = total_length - (left_distance_from_first[i] - left_distance_from_first[next_index]);
        }
        lli right_distance = total_length - left_distance;
        if (left_distance > right_distance) break;
        cost_left += (left_distance * demand[next_index]);
        cost_right -= (right_distance * demand[next_index]);
        start_index = next_index;
      }
      final_rs = min(final_rs, cost_left + cost_right);
    }

    // Output
    cout << final_rs << "\n";
  }
}
