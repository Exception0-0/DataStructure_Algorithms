#include<iostream>
using namespace std;
static int count = 0;
int tower(int n,char from,char to,char aux)
{
	if(n == 1)
	{
		cout<<"Disk "<<n<<" is Move From "<<from<<" To "<<to<<"\n";
		count++;
	}
	else
	{
		tower(n-1,from,aux,to);
		cout<<"Disk "<<n<<" is Move From "<<from<<" To "<<to<<"\n";
		count++;
		tower(n-1,aux,to,from);
	}
	return count;
}
int main()
{
	int n;
	cout<<"Enter Total Disks: ";
	cin>>n;
	int total = tower(n,'A','B','C');
	cout<<"Total Disk Moves: "<<total<<"\n";
	return 0;
}