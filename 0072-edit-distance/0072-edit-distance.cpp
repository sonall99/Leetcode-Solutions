class Solution {
    int dp[501][501];
    int solve(int i,int j,int m,int n,string word1, string word2){
        if(i==m) return (n-j);
        if(j==n) return (m-i);
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,m,n, word1,word2);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int insertC =1+solve(i,j+1,m,n,word1,word2);
        int deleteC =1+solve(i+1,j,m,n,word1,word2);
        int replaceC =1+solve(i+1,j+1,m,n,word1,word2);

        return dp[i][j]=min({insertC,deleteC,replaceC});

    }
public:
    int minDistance(string word1, string word2) {
        return solve(0,0,word1.size(),word2.size(),word1,word2);
    }
};