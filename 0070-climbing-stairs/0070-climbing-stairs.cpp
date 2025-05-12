class Solution {
int dp[50];
int solve(int n){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    return  dp[n]=solve(n-1)+solve(n-2);
}
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
        
    }
};