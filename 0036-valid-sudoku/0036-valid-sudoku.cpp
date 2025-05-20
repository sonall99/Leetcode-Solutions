class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        set<string>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                string r=string(1,board[i][j])+"row"+to_string(i);
                string c=string (1,board[i][j])+"col"+to_string(j);
                string mat=string(1,board[i][j])+"mat"+to_string(i/3)+to_string(j/3);
                if(st.find(r)!=st.end()||st.find(c)!=st.end()||st.find(mat)!=st.end()) return false;
                st.insert(r);
                st.insert(c);
                st.insert(mat);
            }
        }
        return true;

    }
}; 