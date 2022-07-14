#include <bits/stdc++.h>
using namespace std;

struct trie {
    struct node {
        vector<node*> next;
        int end; int alpha;
        node(int end_ = 0, int alpha_ = 26) : end(end_), alpha(alpha_){
            next = {vector<node*>(alpha, nullptr)};
        }
    };

    node* top;
    char norm;

    trie(char norm_ = 'a') : norm{norm_} {
        top = new node;
    }
    ~trie() {
        queue<node*> q;
        q.push(top);
        while(!q.empty())
        {
            node* n = q.front(); q.pop();
            for (auto i : n->next)
                if (i)
                    q.push(i);
            delete n;
        }
    }
    void insert(string s) {
        node* crawler = top;
        for (auto c : s)
        {
            int index = c - norm;
            if (!crawler->next[index])
                crawler->next[index] = new node;
            crawler = crawler->next[index];
        }
        crawler->end++;
    }
    bool search(string s) {
        node* crawler = top;
        for (auto c : s)
        {
            int index = c - norm;
            if (!crawler->next[index])
                return false;
            crawler = crawler->next[index];
        }
        if (!crawler->end)
            return false;
        return true;
    }
    void remove(string s) {
        node* crawler = top;
        for (auto c : s)
        {
            int index = c - norm;
            if (!crawler->next[index])
                return;
            crawler = crawler->next[index];
        }
        if (!crawler->end)
            return;
        crawler->end--;
    }
};
