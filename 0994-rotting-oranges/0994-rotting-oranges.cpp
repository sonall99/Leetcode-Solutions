class Solution {
    int bfs(vector<vector<int>>& grid, queue<pair<pair<int, int>, int>>& pq, int m, int n,int fresh)
{
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
        int r=pq.front().first.first;
        int c=pq.front().first.second;
        int t=pq.front().second;
        pq.pop();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1&&vis[nr][nc]!=2){
                grid[nr][nc]=2;
                pq.push({{nr,nc},t+1});
                fresh--;
                ans=max(ans,t+1);
                vis[nr][nc]=2;

            }
        }
        }
        if(fresh!=0) return -1;
        return ans;
    }

public:

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>pq;
        
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) {
                    pq.push({{i,j},0});
                    vis[i][j]=2;
                    }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int ans=bfs(grid,pq,m,n,fresh);
        
        return ans;
        
    }
};