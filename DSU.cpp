#include <bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> Size,parent;
    public:
    dsu(int si){
        Size.resize(si+10);
        parent.resize(si+10);
        fill(all(Size),1);
        iota(all(parent),0);
    }
    int get_parent(int i){
        if(parent[i] == i) return i;
        return parent[i] = get_parent(parent[i]);
    }
    void Union(int a,int b){
        int parent_A = get_parent(a);
        int parent_B = get_parent(b);

        if(parent_A == parent_B) return;

        if(Rank[parent_A] >= Rank[parent_B]){
            parent[parent_B] = parent_A;
            Rank[parent_A] += Rank[parent_B];
        }
        else{
            parent[parent_A] = parent_B;
            Rank[parent_B] += Rank[parent_A];
        }
    }
};
