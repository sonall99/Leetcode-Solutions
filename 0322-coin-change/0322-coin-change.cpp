class Solution {
    int mini=INT_MAX;
    void solve(vector<int>& coins,vector<int>& ds,int amt,int ind,vector<vector<int>>ans,int n){
        if(ind==n) return ;
        if(amt==0){
            ans.push_back(ds);
            // for(int i:ds){
            //     cout<<i;
            // }
            // cout<<endl;
            int x=ds.size();
            mini=min(mini,x);
            return;
            
        }
        if(coins[ind]<=amt){
            ds.push_back(coins[ind]);
            solve(coins,ds,amt-coins[ind],ind,ans,n);
            ds.pop_back();
        }
        solve(coins,ds,amt,ind+1,ans,n);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>ds;
        vector<vector<int>>ans;
        solve(coins,ds,amount,0,ans,n);
        // int mini=INT_MAX;
        // for(vector<int> i:ans){
        //     int s=i.size();
        //     mini=min(mini,s);
        // }
        return mini==INT_MAX?-1:mini;
        
    }
};