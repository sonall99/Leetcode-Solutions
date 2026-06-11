class Solution {
    int max_depth=0;

    long long fastPower(long long base, long long exponent, long long mod) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent & 1) { // odd exponent
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exponent >>= 1; // exponent /= 2
    }

    return result;
}
    void dfs(vector<vector<int>>&adj,int node,int par,int depth){
        max_depth=max(max_depth,depth);
        for(auto &i:adj[node]){
            if(i==par) continue;
            dfs(adj,i,node,depth+1);
        }
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod=1e9+7;
        int n= edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,1,0,0);
        int ans=fastPower(2,max_depth-1,mod);
        return ans;
    }
};