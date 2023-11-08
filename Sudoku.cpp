#include<bits/stdc++.h>
using namespace std;

template<class T>
void display(vector<vector<T>> &A)
{
    for(auto &T1:A)
    {
        for(auto &T2:T1)
            cout<<T2<<" ";
        cout<<"\n";
    }
}

vector<char> col(9,'0');
vector<vector<char>> Matrix(9,col);
vector<int> Missing[9];
bitset<10> visited;

bool is(char A)
{
	if(A >= '1' && A <= '9') return true;
	return false;
}

bool isUniqeC()
{
	for(auto &T:Matrix)
	{
		visited.reset();
		for(auto &T1:T)
		{
			if(is(T1) && !visited[T1-'0'])
				visited[T1-'0'] = true;
			else if(is(T1))
                return false;
		}
	}
	return true;
}

bool isUniqeR()
{
	for(int i=0;i<9;i++)
	{
		visited.reset();
		for(int j=0;j<9;j++)
		{
			if(is(Matrix[j][i]) && !visited[Matrix[j][i]-'0'])
				visited[Matrix[j][i]-'0'] = true;
			else if(is(Matrix[j][i])) 
                return false;
		}
	}
	return true;
}

bool isUniqeB()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			visited.reset();
			for(int k=i*3;k<i*3+3;k++)
			{
				for(int k1=j*3;k1<j*3+3;k1++)
				{
					if(is(Matrix[k][k1]) && !visited[Matrix[k][k1]-'0'])
						visited[Matrix[k][k1]-'0'] = true;
					else if(is(Matrix[k][k1]))
                        return false;
				}
			}	
		}
	}
	return true;
}

bool isValid()
{
	visited.reset();
	visited[0] = true;
	if(!isUniqeC())
		return false;
	if(!isUniqeR())
		return false;
	if(!isUniqeB())
		return false;
	return true;
}

void SearchMissing()
{
	for(int i=0,cnt=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			visited.reset();
			for(int k=i*3;k<i*3+3;k++)
			{
				for(int k1=j*3;k1<j*3+3;k1++)
				{
					if(is(Matrix[k][k1]))
						visited[Matrix[k][k1]-'0'] = true;
				}
			}
			for(int k1=1;k1<=9;k1++)
				if(!visited[k1])
					Missing[cnt].push_back(k1);
			cnt++;
		}
	}
}

int block(int i,int j)
{
	if(i >=0 && j >=0 && i < 3 && j < 3) return 0;
	if(i >=0 && j >=3 && i < 3 && j < 6) return 1;
	if(i >=0 && j >=6 && i < 3 && j < 9) return 2;
	
	if(i >=3 && j >=0 && i < 6 && j < 3) return 3;
	if(i >=3 && j >=3 && i < 6 && j < 6) return 4;
	if(i >=3 && j >=6 && i < 6 && j < 9) return 5;

	if(i >=6 && j >=0 && i < 9 && j < 3) return 6;
	if(i >=6 && j >=3 && i < 9 && j < 6) return 7;
	if(i >=6 && j >=6 && i < 9 && j < 9) return 8;
	
	return -1;
}

bool fill(int i,int j)
{
	if(isValid());
	else 
        return false;
    if(j >= 9) j = 0,i++;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(Matrix[i][j] == '.')
			{
				int BN = block(i,j);bool flag = false;
				for(auto &T:Missing[BN])
				{
					if(T == 0) continue;
					Matrix[i][j] = T + '0';
					T = 0,flag = true;
					if(!fill(i,j+1))
					{
						// backtracking
						T = Matrix[i][j] - '0';
						Matrix[i][j] = '.';
						flag = false;
					}
                    else break;
				}
				if(!flag) return false;
			}
		}
	}
	return true;
}
int main()
{
	// ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<"Paste Sudoku: \n";
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>Matrix[i][j];
	SearchMissing();
    cout<<"\n";
	if(fill(0,0))
		display(Matrix);
	else 
		cout<<"InValid Sudoku\n";
	return 0;
}

/*

4 . . . . . 1 . 8
. . . . 8 3 . . .
. . . . 9 . 5 . 7
. 6 2 4 . . . . .
3 . 9 . . . 2 . 1
. . . . . 7 4 6 .
5 . 8 . 4 . . . .
. . . 8 1 . . . .
2 . 7 . . . . . 6

*/