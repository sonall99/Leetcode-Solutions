class Solution {
public:
int dp[46];
int ways(int steps,int n){
    if(steps==n){
        return 1;
    }
    int dist_ways=0;
    if(steps>n)return 0;
    if(dp[steps]!=-1) return dp[steps];
    for(int i=1;i<=2;i++){
        dist_ways+=(ways(steps+i,n));
    }
    return dp[steps]=dist_ways;
}
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return ways(0,n);
        
    }
};