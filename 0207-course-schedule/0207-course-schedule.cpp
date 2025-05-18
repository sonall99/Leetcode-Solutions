class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto i:prerequisites){
            int u=i[1];
            int v=i[0];
            adj[u].push_back(v);
        }
        int n=numCourses;
        vector<int>ind(n,0);
        for(int i=0;i<prerequisites.size();i++){
            ind[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adj[node]){
                ind[i]--;
                if(ind[i]==0) q.push(i);

            }


        }
        if(ans.size()==n) return true;
        return false;

    }
};