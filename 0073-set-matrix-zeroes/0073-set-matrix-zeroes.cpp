class Solution {
    void solve(int i,int j,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        for(int r=0;r<n;r++){
            matrix[r][j]=0;
        }
        for(int c=0;c<m;c++){
            matrix[i][c]=0;
        }
        return ;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>>st;
         int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) st.insert({i,j});
            }
        }
        for(auto i:st){
            solve(i.first,i.second,matrix);
        }
        return;

    }
};