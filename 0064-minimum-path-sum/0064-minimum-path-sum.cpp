class Solution {
private:
int dp[201][201];
private:
int Solve(vector<vector<int>>&triangle,int row,int col,int n,int m){
    // if(row>=n || col >=m)return 1e9;
    if(row == n-1 && col==m-1)return triangle[row][col];
    if(dp[row][col] !=-1)return dp[row][col];
    int case1=1e9;
    int case2=1e9;
    if(row+1<n)
     case1= Solve(triangle,row+1,col,n,m);
     if(col+1<m)
     case2= Solve(triangle,row,col+1,n,m);
    return dp[row][col]=triangle[row][col]+min(case1,case2);

}
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return Solve(grid,0,0,grid.size(),grid[0].size());
        
    }
};