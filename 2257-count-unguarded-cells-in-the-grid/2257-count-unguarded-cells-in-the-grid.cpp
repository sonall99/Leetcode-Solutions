class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>v(m,vector<int>(n,0));
        for(auto i :guards){
            v[i[0]][i[1]]=1;
        }
        for(auto i :walls){
            v[i[0]][i[1]]=2;
        }
        for(auto i:guards){
            int r=i[0];
            int c=i[1];
            for(int row=r-1;row>=0;row--){
                if(v[row][c]==1 || v[row][c]==2) break;
                v[row][c]=3;
            }
            for(int row=r+1;row<m;row++){
                if(v[row][c]==1 || v[row][c]==2) break;
                v[row][c]=3;
            }
            for(int col=c+1;col<n;col++){
                if(v[r][col]==1 || v[r][col]==2) break;
                v[r][col]=3;
            }
            for(int col=c-1;col>=0;col--){
                if(v[r][col]==1 || v[r][col]==2) break;
                v[r][col]=3;
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0) c++;
            }
        }
        return c;
    }
};