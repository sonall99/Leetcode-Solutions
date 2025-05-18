class Solution {
vector<int>dp;
private:
int Recursion(vector<int>&nums,int idx,int n){
    if(idx>=n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int take=nums[idx]+Recursion(nums,idx+2,n);
    int notTake=Recursion(nums,idx+1,n);
    return dp[idx]=max(take, notTake);


}

public:
    int rob(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int n=nums.size();
        dp.assign(n+1,-1);
        for(auto i:dp)cout<<i<<endl;
        return Recursion(nums,0,nums.size());
        
    }
};