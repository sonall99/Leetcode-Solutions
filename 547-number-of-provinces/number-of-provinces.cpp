class Solution {
    void dfs(int node,vector<vector<int>>&v,vector<bool>&vis){
       vis[node]=true;
       for(int i=0;i<v.size();i++){
        if(v[node][i] && !vis[i]) dfs(i,v,vis);
       }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>v(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                
                dfs(i,isConnected,v);
                cnt++;
            }
        }
        return cnt;
    }
};