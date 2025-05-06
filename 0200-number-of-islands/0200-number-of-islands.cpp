class Solution {
     void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 &&nr<m&&nc>=0&&nc<n&&!vis[nr][nc] &&grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    c++;
                    bfs(grid,i,j,vis);
                }
            }

        }
        return c;
    }
};