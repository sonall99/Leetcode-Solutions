class Solution {
// int dp[201][201];
private:
int Solve(vector<vector<int>>&triangle,int row,int col,int n,int m){
    // if(row>=n || col >=m)return 1e9;
    if(row == n-1)return triangle[row][col];
    int case1=1e9;
    int case2=1e9;
    if(row+1<n)
     case1= Solve(triangle,row+1,col,n,m);
     if(row+1<n && col+1<m)
     case2= Solve(triangle,row+1,col+1,n,m);
    return triangle[row][col]+min(case1,case2);

}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        // if(n==1){
        //     vector<int >arr=triangle[0];
        //     return *min_element(arr.begin(),arr.end());
        // }
        return Solve(triangle,0,0,n,n);
        
    }
};