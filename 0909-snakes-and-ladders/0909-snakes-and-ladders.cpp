class Solution {
public:
pair<int,int> findcord(int x,int n){
       int  row=(n-1)-((x-1)/n);
       int col=(x-1)%n;
       if((row%2 &&n%2) ||(row%2==0 &&n%2==0)){
         col=(n-1)-((x-1)%n);
       }
       return{row,col};

    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        int n=board.size();
        q.push(1);
        int level=0;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[n-1][0] =1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                if(node==n*n) return level;
                for(int i=1;i<=6;i++){
                    int newval=node+i;
                    if(newval>n*n) break;
                    pair<int,int>cord=findcord(newval,n);
                    int x=cord.first;
                    int y=cord.second;
                    if(!vis[x][y]){
                    if(board[x][y]==-1){
                        q.push(newval);
                        vis[x][y]=1;
                    }
                    else{
                        q.push(board[x][y]);
                        vis[x][y]=1;
                    }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};