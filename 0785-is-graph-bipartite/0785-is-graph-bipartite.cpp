class Solution {
    bool check(vector<vector<int>>& graph,vector<int>&vis,int num,vector<int>&color){
        queue<int>q;
        vis[num]=1;
        color[num]=0;
        q.push(num);
        while(!q.empty()){
            int node=q.front();
            q.pop();
        for(int i:graph[node]){
            if(!vis[i]){
                vis[i]=1;
                color[i]=!color[node];
                q.push(i);
            }
            else{
                if(color[i]==color[node]) return false;
            }
        }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>color(m,-1);
        int n=graph[0].size();
        vector<int>vis(m,0);
        for(int i=0;i<m;i++){
                if(!vis[i]){
                    if(!check(graph,vis,i,color))return false;
            }

        }
        return true;
    }
};