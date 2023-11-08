#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> state = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6},{0,4,8}};
int probability(vector<vector<int>> &grid,int i,int j,int turn)
{
    grid[i][j] = turn;
    probability(grid,i,j,(turn==1? 2:1));
}
int main()
{
    vector<vector<int>> grid = {{0,0,0},{0,0,0},{0,0,0}};
    while(win(grid))
    {
        int row,col;cin>>row>>col;
        if(!grid[row][col])
            grid[row][col] = 1;
        int mx = -1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j] == 0)
                {
                    int val = probability(grid,i,j,2);
                    if(mx < val)
                    {
                        mx = val;
                        row = i;
                        col = j;
                    }
                }
            }
        }
        grid[row][col] = 2;
    }
    return 0;
}