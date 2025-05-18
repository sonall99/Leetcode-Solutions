class Solution {
public:
int n;
int dp[2501][2501];
int LIS(int ind,vector<int>&nums,int par){
    if(ind>=n) return 0;
    if(par!=-1 && dp[ind][par]!=-1) return dp[ind][par];
    int take=0;
    if(par==-1 ||nums[par]<nums[ind]){
        take=1+LIS(ind+1, nums,ind);

    }
    int not_take=LIS(ind+1,nums,ind);
    if(par==-1) return max(take,not_take);
    return dp[ind][par]=max(take,not_take);
}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return LIS(0,nums,-1);
    }
};