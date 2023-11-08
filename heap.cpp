#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &heap,int ele)
{
	heap.push_back(ele);
	int index = heap.size()-1;
	while(index != 1 && heap[index] > heap[index/2])
	{
		swap(heap[index],heap[index/2]);
		index /= 2;
	}
}
void remove(vector<int> &heap)
{
	swap(heap[1],heap.back());
	heap.pop_back();
	int index = 1;
	while(index*2+1 < heap.size())
	{
		int child = (heap[index*2] > heap[index*2+1]? index*2:index*2+1);
		if(heap[index] < heap[child]) swap(heap[index],heap[child]);
		else break;
		index = child;
	}
	if(index*2 < heap.size() && heap[index] < heap[index*2]) swap(heap[index],heap[index*2]);
}
// void hepify(vector<int> &arr)
// {
// 	bool flag = false;
// 	if(arr.size() & 1) arr.push_back(-1),flag = true; // max heap if mean 1e9 have to push
// 	int index = arr.size()-1;
// 	while(index > 1)
// 	{
// 		int child = (arr[index] > arr[index-1]? index:index-1);
// 		if(arr[index/2] < arr[child]) swap(arr[index/2],arr[child]);
// 		index -= 2;
// 	}
// 	if(flag) arr.pop_back();
// }
int main()
{
	// vector<int> heap = {-1};
	// insert(heap,10);
	// insert(heap,1);
	// insert(heap,5);
	// insert(heap,20);
	// insert(heap,60);
	// insert(heap,12);
	// insert(heap,82);
	// for(int &i:heap) cout<<i<<" ";
	// cout<<"\n";
	// remove(heap);
	// for(int &i:heap) cout<<i<<" ";
	// cout<<"\n";
	// remove(heap);
	// for(int &i:heap) cout<<i<<" ";
	// cout<<"\n";
	// remove(heap);
	// for(int &i:heap) cout<<i<<" ";
	// cout<<"\n";
	// remove(heap);
	// for(int &i:heap) cout<<i<<" ";
	// cout<<"\n";
	vector<int> arr = {-1,20,10,30,5,50,40};
	hepify(arr);
	for(int &i:arr) cout<<i<<" ";
	cout<<"\n";
	return 0;
}