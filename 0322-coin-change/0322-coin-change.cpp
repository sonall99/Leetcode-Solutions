class Solution {

public:
int dp[13][10001];
int check(int ind,vector<int>& coins, int amount,int n){
    if(amount==0) return 0;
    if(ind>=n && amount !=0) return INT_MAX-1;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int take=0;
    if(coins[ind]<=amount) {
        take=1+check(ind,coins,amount-coins[ind],n);
    }
    int not_take= check(ind+1,coins,amount,n);
    return dp[ind][amount]=min(take,not_take);

}

    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= check(0,coins,amount,coins.size());
        return (ans==INT_MAX-1)?-1:ans;
    }
};