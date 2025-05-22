class Solution {
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathvis,int i,vector<int>&check){
        vis[i]=1;
        pathvis[i]=1;
        for(int j:graph[i]){
            if(!vis[j]){
                if(dfs(graph,vis,pathvis,j,check)) return true;
            }
            else{
                if(pathvis[j]) return true;
            }
        }
        check[i]=1;
        pathvis[i]=0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>check(n,0);
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,pathvis,i,check);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]== 1) ans.push_back(i);
        }
        return ans;
        
    }
};