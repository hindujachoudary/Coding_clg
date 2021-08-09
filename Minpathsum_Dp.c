class Solution {
public:

    int dp[1000][1000];
    int minvalue(vector<vector<int>>&grid,int m,int n,int i,int j){
        int ans1=1000000,ans2=1000000;
        if(i == m-1 && j == n-1)
            return grid[i][j];
        if(dp[i][j])
            return dp[i][j];
        if( i+1 < m)
            ans1=minvalue(grid,m,n,i+1,j);
        if( j+1 < n)
            ans2=minvalue(grid,m,n,i,j+1);
        return dp[i][j]=grid[i][j]+min(ans1,ans2);

    }


    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        memset(dp,0,sizeof(dp));

        return minvalue(grid,m,n,0,0);



    }
};
