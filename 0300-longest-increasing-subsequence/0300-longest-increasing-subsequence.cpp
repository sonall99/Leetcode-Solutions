class Solution {
    int dp[2501][2501];
    int n;
    int lis(int ind,vector<int>& nums,int prev){
        if(ind>=n) return 0;
        int take=0;
        if(prev!=-1 && dp[ind][prev]!=-1) return dp[ind][prev];
        if(prev==-1 ||nums[prev]<nums[ind]){
             take=1+lis(ind+1,nums,ind);
        }
        int not_take=lis(ind+1,nums,prev);
        if(prev!=-1){
            return dp[ind][prev]=max(take,not_take);
        }
        return max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
         n=nums.size();
        return lis(0,nums,-1);
    }
};