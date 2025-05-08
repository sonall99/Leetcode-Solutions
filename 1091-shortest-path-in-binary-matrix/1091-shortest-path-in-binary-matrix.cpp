class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 ||grid[n-1][n-1]==1) return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dr[]={-1,0,1,0,-1,1,-1,1};
        int dc[]={0,1,0,-1,-1,1,1,-1};
        while(!q.empty()){
             int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r==n-1 &&c==n-1)return d+1;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 &&nr<n&&nc>=0 &&nc<n && !vis[nr][nc]&& grid[nr][nc]==0){
                    q.push({d+1,{nr,nc}});
                    vis[nr][nc]=1;

                }
            }
        }
        return -1;

    }
};