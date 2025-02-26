#include <bits/stdc++.h>
#define Mxv 100010
#define inf 1000000000
#define linf 1000000000000000000
#define fi first
#define se second
#define ll long long
// #define u unsigned
#define null NULL
#define pb push_back
#define ob pop_back
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i]
#define print(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "
#define printR(arr,n) for(int i=n-1;i>=0;i--) cout<<arr[i]<<" "
#define len size()
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)
#define TLE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int mod = 1e9+7;

class dsu{
    const int n = 1000;
    int Rank[n+10],parent[n+10];
    public:
    dsu(){
        for(int i=0;i<n+10;i++) Rank[i] = 1;
        iota(parent,parent+n+10,0);
    }
    int get_parent(int i){
        if(parent[i] == i) return i;
        return parent[i] = get_parent(parent[i]);
    }
    void Union(int a,int b){
        int parent_A = get_parent(a);
        int parent_B = get_parent(b);
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
 
/*

	8 -1 -4 2 6 -3

	-4 -3 -1 2 6 8

	-4 3 1 2 6 8
	-4 1 2 3 6 8

*/
