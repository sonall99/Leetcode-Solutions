class Solution {
private:
int target=0;
// vector<vector<int>>dp;
int dp[201][10000+10];
bool solve(vector<int>&nums,int idx,int n,int sum){
    if(idx>=n || target<0) return false;
    if(target==sum)return true;
    if(dp[idx][sum] != -1)return dp[idx][sum];
    int take =solve(nums,idx+1,n,sum+nums[idx]);
    int notTake=solve(nums,idx+1,n,sum);
    return dp[idx][sum]= take || notTake;
}
public:
    bool canPartition(vector<int>& nums) {
    long long sum=accumulate(nums.begin(),nums.end(),0LL);
    if(sum&1)return false;
    // return true;
    target=sum/2;
    memset(dp,-1,sizeof(dp));
    // dp.assign(nums.size()+1,vector<int>(target+1000,-1));
    return solve(nums,0,nums.size(),0);
        
    }
};