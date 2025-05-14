class Solution {
     int bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j,int id){
        int cnt=0;
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
            grid[r][c]=id;
            q.pop();
            cnt+=1;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 &&nr<m&&nc>=0&&nc<n&&!vis[nr][nc] &&grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }

        }
        return cnt;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<int>>v(m,vector<int>(n,1));
        if(v==grid) return m*n;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int id=2;
        map<int,int>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                   int cnt=bfs(grid,vis,i,j,id);
                   mp[id]=cnt;
                   id++;
                }
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>s;
                    vector<int>dr={-1,0,1,0};
                    vector<int>dc={0,-1,0,1};
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]>1){
                            s.insert(grid[nr][nc]);
                        }
                    }
                    int size=1;
                    for(int i:s){
                        size+=mp[i];
                    }
                    maxi=max(maxi,size);


                }
            }
        }
        return maxi;
    
        
    }
};