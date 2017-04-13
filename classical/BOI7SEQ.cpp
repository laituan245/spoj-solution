// BOI7SEQ - Sequence
// http://www.spoj.com/problems/BOI7SEQ/

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
#define MAX_INT 2000000000
using namespace std;

struct NODE {
    int value;
    NODE * prev;
    NODE * next;
};

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

NODE * make_node (int val) {
    NODE * node = new NODE;
    node->prev = NULL;
    node->next = NULL;
    node->value = val;
    return node;
}

void remove_node (NODE * node) {
    NODE * previous_node = node->prev; // Always exists for this specific case
    NODE * next_node = node->next;     // Always exists for this specific case
    previous_node->next = next_node;
    next_node->prev = previous_node;
    delete(node);
}

int main() {
    unsigned long long int finalRs = 0;
    int n, a, nbElementsRemoved = 0;
    NODE * root = make_node(MAX_INT);
    NODE * cur = root;
    inp(n);
    for (int i = 0; i <= n; i++) {
        if (i < n)
            inp(a);
        else
            a = MAX_INT;
        NODE * tmp = make_node(a);
        tmp->prev = cur;
        cur->next = tmp;
        cur = tmp;
    }


    cur = root->next;
    while (nbElementsRemoved < n-1) {
        NODE * previous_node = cur->prev;
        NODE * next_node = cur->next;
        if (cur->value <= previous_node->value && cur->value <= next_node->value) {
            finalRs += min(previous_node->value, next_node->value);
            cur->value = min(previous_node->value, next_node->value);
            nbElementsRemoved += 1;
            if (previous_node->value < next_node->value) {
                remove_node(previous_node);
            } else {
                remove_node(next_node);
            }
        } else {
            cur = cur->next;
        }
    }

    cout << finalRs << "\n";
}
