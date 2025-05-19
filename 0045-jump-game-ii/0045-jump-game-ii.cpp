class Solution {
public:
int dp[10001];
int solve(int idx,vector<int>& nums,int n){
    if(idx==n-1) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int mini=INT_MAX;
    for(int i=1;i<=nums[idx];i++){
        if(idx+1<n){
        int jump=solve(idx+i,nums,n);
        if(jump!=INT_MAX){
        mini=min(mini,1+jump);
        }
        }
    }
    return dp[idx]=mini;
}
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,nums.size());
    }
};