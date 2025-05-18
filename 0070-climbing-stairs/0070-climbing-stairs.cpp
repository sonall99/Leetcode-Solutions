class Solution {
    int dp[46];
    int recursion(int level,int &n){
        if(level==n) return 1;
        if(level>n) return 0;
        int ans=0;
        if(dp[level]!=-1) return dp[level];
        for(int i=1;i<=2;i++){
            if((level+i)<=n){
                int ways=recursion(level+i,n);
                ans+=ways;
            }
        }
        dp[level]=ans;
        return ans;
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return recursion(0,n);
        
    }
};