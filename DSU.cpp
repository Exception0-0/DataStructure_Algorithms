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

// int Parent[2010];
// int Rank[2010];
// int getParent(int i)
// {
// 	if(Parent[i] == i) return i;
// 	return getParent(Parent[i]);
// }
// void Union(int a,int b)
// {
// 	int parent_A = getParent(a);
// 	int parent_B = getParent(b);
// 	if(Rank[parent_A] >= Rank[parent_B])
// 	{
// 		Parent[parent_B] = parent_A;
// 		Rank[parent_A] += Rank[parent_B];
// 	}
// 	else
// 	{
// 		Parent[parent_A] = parent_B;
// 		Rank[parent_B] += Rank[parent_A];
// 	}
// }
// bool isCycle(int u,int v)
// {
// 	return getParent(u) == getParent(v);
// }

int main()
{
	TLE;
	int t,google=1;cin>>t;
	while(t--)
	{
		// int n;cin>>n;
		// string a;cin>>a;
		// string b;cin>>b;
		// int m = 0,f = 0;
		// for(int i=0;i<n;i++)
		// {
		// 	if(a[i] == 'S')
		// 	{
		// 		if(b[i] == 'R') f++;
		// 		else if(b[i] != 'S') m++;
		// 	}
		// 	else if(a[i] == 'P')
		// 	{
		// 		if(b[i] == 'S') f++;
		// 		else if(b[i] != 'P') m++;
		// 	}
		// 	else
		// 	{
		// 		if(b[i] == 'P') f++;
		// 		else if(b[i] != 'R') m++;
		// 	}
		// }
		// cout<<max(0,f-m)<<"\n";
		
	}
}
 
 
 
/*

	8 -1 -4 2 6 -3

	-4 -3 -1 2 6 8

	-4 3 1 2 6 8
	-4 1 2 3 6 8

*/
