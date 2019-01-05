// MOZPWS - Playing With Subarray
// https://www.spoj.com/problems/MOZPWS/
// Make use of segment tree
// A lot of redundant code. May need cleanup

#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include <set>
#define lli long long int
using namespace std;

int n; // Size of the array
int k; // Length of the sub-array
lli A[100001];
lli B[100001];
lli first_tree[500005]; // For computing the min of any sub-array A[i..j]
lli second_tree[500005]; // For computing the max of a set of K_min_subarray values

bool is_overlap(int left1, int right1, int left2, int right2) {
    if (right1 < left2) return false;
    if (right2 < left1) return false;
    return true;
}

void construct_first_tree(int node_nb, int left, int right) {
    if (left > right) return;
    if (left == right) {
        first_tree[node_nb] = A[left];
        return;
    }
    int mid = (left + right) / 2;
    construct_first_tree(node_nb * 2, left, mid);
    construct_first_tree(node_nb * 2 + 1, mid + 1, right);
    first_tree[node_nb] = min(first_tree[node_nb * 2], first_tree[node_nb * 2 +1]);
}

lli get_min_first_tree(int node_nb, int left, int right, int query_left, int query_right) {
    if (query_left <= left && right <= query_right) return first_tree[node_nb];
    int mid = (left + right) / 2;
    lli final_ans = +2000000000000000000;
    if (is_overlap(left, mid, query_left, query_right)) {
        lli query1 = get_min_first_tree(node_nb * 2, left, mid, query_left, query_right);
        final_ans = min(final_ans, query1);
    }
    if (is_overlap(mid + 1, right, query_left, query_right)) {
        lli query2 = get_min_first_tree(node_nb * 2 + 1, mid + 1, right, query_left, query_right);
        final_ans = min(final_ans, query2);
    }
    return final_ans;
}

void construct_second_tree(int node_nb, int left, int right) {
    if (left > right) return;
    if (left == right) {
        second_tree[node_nb] = B[left];
        return;
    }
    int mid = (left + right) / 2;
    construct_second_tree(node_nb * 2, left, mid);
    construct_second_tree(node_nb * 2 + 1, mid + 1, right);
    second_tree[node_nb] = max(second_tree[node_nb * 2], second_tree[node_nb * 2 +1]);
}

lli get_max_second_tree(int node_nb, int left, int right, int query_left, int query_right) {
    if (query_left <= left && right <= query_right) return second_tree[node_nb];
    int mid = (left + right) / 2;
    lli final_ans = -2000000000000000000;
    if (is_overlap(left, mid, query_left, query_right)) {
        lli query1 = get_max_second_tree(node_nb * 2, left, mid, query_left, query_right);
        final_ans = max(final_ans, query1);
    }
    if (is_overlap(mid + 1, right, query_left, query_right)) {
        lli query2 = get_max_second_tree(node_nb * 2 + 1, mid + 1, right, query_left, query_right);
        final_ans = max(final_ans, query2);
    }
    return final_ans;
}

int main() {
    int t; // Number of test cases
    int nb_queries; // Number of queries
    int query_left, query_right;
    scanf("%d", &t);
    for (int z = 0; z < t; z++) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &A[i]);
        scanf("%d", &nb_queries);
        construct_first_tree(1, 1, n);

        for (int i = 1; i <= n; i++) {
            int j = i + k - 1;
            if (j > n) break;
            B[i] = get_min_first_tree(1, 1, n, i, j);
        }
        construct_second_tree(1, 1, n-k+1);

        printf("Case %d:\n", (z+1));
        for (int zz = 0; zz < nb_queries; zz++) {
            scanf("%d %d", &query_left, &query_right);
            if (query_right - query_left + 1 < k)
                printf("Impossible\n");
            else {
                lli final_ans = get_max_second_tree(1, 1, n-k+1, query_left, query_right-k+1);
                printf("%lld\n", final_ans);
            }
        }
    }
}
