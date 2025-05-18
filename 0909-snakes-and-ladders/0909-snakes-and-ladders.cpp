class Solution {
    pair<int,int> get_cord(int x,int n){
       int  row=(n-1)-((x-1)/n);
       int col=(x-1)%n;
       if((row%2 &&n%2) ||(row%2==0 &&n%2==0)){
         col=(n-1)-((x-1)%n);
       }
       return{row,col};

    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<int>q;
        q.push(1);
        int level=0;
        vis[n-1][0]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr_val=q.front();
                q.pop();
                if(curr_val==n*n) return level;
                for(int i=1;i<=6;i++){
                    int new_val=curr_val+i;
                    if(new_val>n*n) break;
                    pair<int,int>cord=get_cord(new_val,n);
                    int x=cord.first;
                    int y=cord.second;
                    if(!vis[x][y]){
                        if(board[x][y]==-1){
                             q.push(new_val);
                             vis[x][y]=1;
                        }
                        else {
                            q.push(board[x][y]);
                            vis[x][y]=1;}
                    }

                }
            }
            level++;
        }
        return -1;
    }
};