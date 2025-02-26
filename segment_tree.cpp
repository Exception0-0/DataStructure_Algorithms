#include<iostream>
#include<vector>
#include <functional>
#include <cassert>
#define len size()
#define fi first
#define se second
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>> tree(n*4);

    function<void(int,int,int)> build = [&](int node,int left,int right){
        // cout<<"Node: "<<node<<"\n";
        assert(node < n*4);

        if(left == right){
            tree[node].fi = arr[left];
            return ;
        }
        int mid = (left + right) / 2;
        build(node*2,left,mid);
        build(node*2+1,mid+1,right);
        tree[node].fi = tree[node*2].fi + tree[node*2+1].fi;
    };

    function<int(int,int,int,int,int)> sum = [&](int node,int left,int right,int l,int r){
        if(r < l) return 0;
        if(left == l && right == r) return tree[node].fi;
        int mid = (left + right) >> 1;
        return sum(node*2,left,mid,l,min(r,mid)) + 
                sum(node*2+1,mid+1,right,max(l,mid+1),r);
    };

    // function<void(int,int,int,int&,int&)> update = [&](int node,int left,int right,int &ind,int &val){
    //     if(left == right){
    //         tree[node].fi = val;
    //     }
    //     int mid = (left + right) >> 1;
    //     if(mid >= ind) update(node*2,left,mid,ind,val);
    //     else update(node*2+1,mid+1,right,ind,val);
    //     tree[node].fi = tree[node*2].fi + tree[node*2+1].fi;
    // };

    // lazy propagation

    function<void(int,int,int,int,int,int)> push = [&](int node,int left,int right,int l,int r,int val){
        if(l > r) return;
        if(left == l && right == r){
            tree[node].se += val;
            return;
        }
        int mid = (left + right) >> 1;
        push(node*2,left,mid,l,min(r,mid),val);
        push(node*2+1,mid+1,right,max(l,mid+1),r,val);
    };

    function<void(int,int,int,int)> update = [&](int node,int left,int right,int val){
        if(left == right){
            val += tree[node].se;
            tree[node].se = 0;
            tree[node].fi += val;
            return;
        }
        int mid = (left + right) >> 1;
        val += tree[node].se;
        tree[node].se = 0;
        update(node*2,left,mid,val);
        update(node*2+1,mid+1,right,val);
        tree[node].fi = tree[node*2].fi + tree[node*2+1].fi;
    };

    build(1,0,n-1);

    for(int i=0;i<tree.len;i++) cout<<tree[i].fi<<" ";
    cout<<"\n";

    push(1,0,n-1,2,6,8);

    for(int i=0;i<tree.len;i++) cout<<tree[i].se<<" ";
    cout<<"\n";

    update(1,0,n-1,0);
    
    for(int i=0;i<tree.len;i++) cout<<tree[i].fi<<" ";
    cout<<"\n";
}