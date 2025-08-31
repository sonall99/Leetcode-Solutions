class Solution {
    private:
    bool isvalid(int r,int c,int a,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if((board[r][i]==a)||(board[i][c]==a)||(board[3*(r/3)+i/3][3*(c/3)+i%3]==a)) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)==true) return true;
                            else{
                                  board[i][j]='.';
                            }

                        }
                        
                    }
                   return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};