class Solution {
    set<string>wordset;
    int n;
    int dp[301];
    bool solve(int ind,string &s,vector<string>& wordDict){
        if(ind>=n) return true;
        if(wordset.find(s)!=wordset.end()) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<n-ind;i++){
            string substring=s.substr(ind,i);
            if(wordset.find(substring)!=wordset.end()&&solve(ind+i,s,wordDict)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(string i:wordDict){
            wordset.insert(i);
        }
        n=s.size();
        
        return solve(0,s,wordDict);
    }
};