#include <bits/stdc++.h>
using namespace std;

//usando lazy propagation
template<typename T>
struct segtree {
    vector<T> tree;
    vector<T> lazy;
    int n;

    segtree(int n_ = 1) : n{n_} {
        tree = vector<T>(2*n);
        lazy = vector<T>(2*n, 0);
    }
    void build (vector<T> v) {
        for (int i = n; i < 2*n; i++)
            tree[i] = v[i - n];
        for (int i = n - 1; i >= 0; i--)
            tree[i] = tree[2*i] + tree[2*i + 1];
    }
    void update(int l, int r, int x, int begin, int end, int pos = 0) {
        if (end < l || r < begin)
            return;
        if (l <= begin && end <= r)
        {
            tree[pos] += (end - begin + 1)*x;
            lazy[pos] += x;
            return;
        }
        int mid = (begin + end)/2;
        propagate(pos, begin, end);
        update(l, r, x, begin, mid, 2*pos);
        update(l, r, x, mid + 1, end, 2*pos + 1);
        tree[pos] = tree[2*pos] + tree[2*pos + 1];
    }
    void propagate(int pos, int begin, int end) {
        int mid = (begin + end)/2;
        lazy[2*pos] += lazy[pos];
        tree[2*pos] += (mid - begin + 1)*lazy[pos];
        lazy[2*pos + 1] += lazy[pos];
        tree[2*pos + 1] == (end - mid)*lazy[pos];
        lazy[pos] = 0;
    }
    int search(int l, int r, int begin, int end, int pos = 0) {
        if (l <= begin && end <= r)
            return tree[pos];
        if (end < l || r < begin)
            return 0;
        int mid = (begin + end)/2;
        return search(l, r, begin, mid, 2*pos) + search(l, r, mid + 1, end, 2*pos + 1); 
    }
};
