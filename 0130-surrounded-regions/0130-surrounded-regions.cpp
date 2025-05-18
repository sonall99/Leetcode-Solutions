class Solution {
    void bfs(vector<vector<char>>& board, vector<vector<int>>&vis, queue<pair<int,int>>&q){
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        int m=board.size();
        int n=board[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]=='O'&&!vis[nr][nc]){
                q.push({nr,nc});
                vis[nr][nc]=1;
            }
        }
        }
        

        
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        queue<pair<int,int>>q;
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                if(board[i][j]=='O'&&!vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
            }
        }
        bfs(board,vis,q);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};