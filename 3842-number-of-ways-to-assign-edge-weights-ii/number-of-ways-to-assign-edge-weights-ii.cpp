using ll = long long;
class Solution {
    const int mod=1e9+7;
    int rows;
    int col;
    vector<vector<int>>up;
    vector<int>depth;
    int lca(int u,int v){
        if(depth[u]<depth[v])  swap(u,v);
        int diff= depth[u]-depth[v];
        for(int j=0;j<col;j++){
            if(diff & (1<<j)){
                u=up[u][j];
            }
        }
        if(u==v) return u;
        for(int j=col-1;j>=0;j--){
            if(up[u][j]==-1) continue;
            if(up[u][j]!=up[v][j]) {
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];

    }
    void dfs(int node,int par,vector<vector<int>>& adj,int dep){
        up[node][0]=par;
        depth[node]=dep;
        for(int e:adj[node]){
            if(e!=par) {
                dfs(e,node,adj,dep+1);
            }
        }
    }
    ll fastpow(ll base,ll exp,ll mod){
        ll res=1;
        while(exp>0){
        if(exp & 1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
        }
        return res;

    }
    
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        rows=n;
        col=log2(n)+1;
        depth.resize(n+1,0);
        up.resize(rows+1,vector<int>(col,-1));
        
        
        vector<vector<int>>adj(n+1);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans;
        dfs(1,-1,adj,0);
        for(int j=1;j<col;j++){
            for(int node=1;node<=rows;node++){
                if(up[node][j-1]!=-1){
                up[node][j]=up[up[node][j-1]][j-1];}
            }
        }
        for(auto &i:queries){
            int ca=lca(i[0],i[1]);
            int k=depth[i[0]]+depth[i[1]]-2*depth[ca];
            if(k==0){
                ans.push_back(0);
            continue;}
            int result=fastpow(2,k-1,mod);
            ans.push_back(result);
        }
        return ans;
    }
};

