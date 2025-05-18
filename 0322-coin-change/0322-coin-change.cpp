class Solution {
    int dp[13][10001];
    int n;
    int rec(int ind,vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(ind>=n &&amount!=0) return INT_MAX-1;
        int res=0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        if(coins[ind]>amount){
            int not_take=0+rec(ind+1,coins,amount);
            res=not_take;
        }
        else if(coins[ind]<=amount){
            int take=1+rec(ind,coins,amount-coins[ind]);
            int not_take=0+rec(ind+1,coins,amount);
            res=min(take,not_take);
        }
        return dp[ind][amount]=res;

        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        n=coins.size();
        int ans= rec(0,coins,amount);
        return (ans==INT_MAX-1)?-1:ans;
    }
};