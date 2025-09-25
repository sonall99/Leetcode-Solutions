class Solution {
public:
int dp[201][201];
    int min_path(int r,int c,vector<vector<int>>& grid,int m ,int n){
        if(r==m-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int case1=INT_MAX,case2=INT_MAX;
        if(r+1<m)  case1=min_path(r+1,c,grid,m,n);
        if(r+1 &&c+1<n) case2=min_path(r+1,c+1,grid,m,n);
        return dp[r][c]=grid[r][c]+min(case1,case2);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int m=triangle.size();
        int n=triangle[0].size();
        return min_path(0,0,triangle,m,m);
    }
};