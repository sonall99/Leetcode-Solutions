class Solution {
    int dp[201][201];
    int min_path(int r,int c,vector<vector<int>>& grid,int m ,int n){
        if(dp[r][c]!=-1) return dp[r][c];
        int case1=INT_MAX,case2=INT_MAX;
        if(r+1<m) int case1=min_path(r+1,c,grid,m,n);
        if(c+1<n) int case2=min_path(r,c+1,grid,m,n);
        return dp[r][c]=min(case1,case2);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        return min_path(0,0,grid,m,n);
    }
};