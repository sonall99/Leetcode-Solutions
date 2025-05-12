class Solution {
vector<vector<int>>dp;
int solve(string s,string t,int i,int j,int n,int m){
    if(i>=n || j>=m){
        // if(s[i]==s[j])return 1;
        // else 
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]= 1+solve(s,t,i+1,j+1,n,m);
    }
    else{
    // int case1=solve(s,t,i+1,j,n,m);
    // int case2=solve(s,t,i,j+1,n,m);
    return dp[i][j]= max(solve(s,t,i+1,j,n,m),solve(s,t,i,j+1,n,m));
    

    }
    // return 0;

}

public:
    int longestCommonSubsequence(string text1, string text2) {

        dp.assign(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,text1.size(),text2.size());
      
        
    }
};