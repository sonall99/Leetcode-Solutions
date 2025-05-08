class Solution {
    bool check(vector<vector<int>>& graph,vector<int>vis,vector<int>clr,int num){
        queue<int>q;
        q.push(num);
        clr[num]=0;
        vis[num]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:graph[node]){
                if(!vis[i]){
                    vis[i]=1;
                    clr[i]=!clr[node];
                    q.push(i);
                }
                else{
                    if(clr[i]==clr[node]) return false;
                }
            }
            

        }   
        return true;     
    
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>clr(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!check(graph,vis,clr,i)) return false;
            }
        }
        return true;
   
    }
};