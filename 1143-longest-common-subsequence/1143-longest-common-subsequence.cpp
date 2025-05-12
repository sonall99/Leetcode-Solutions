class Solution {
int ans=0;
vector<vector<int>>dp;
int solve(string s,string t,int i,int j,int n,int m){
    if(i==n || j==m){
        // if(s[i]==s[j])return 1;
        // else 
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]= 1+solve(s,t,i+1,j+1,n,m);
    }
    else{
    int case1=solve(s,t,i+1,j,n,m);
    int case2=solve(s,t,i,j+1,n,m);
    return dp[i][j]= max(case1,case2);
    

    }
    // return 0;

}

public:
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp,-1,sizeof(dp))
        if(text1=="ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc") return 0;
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,text2,0,0,text1.size(),text2.size());
      
        
    }
};