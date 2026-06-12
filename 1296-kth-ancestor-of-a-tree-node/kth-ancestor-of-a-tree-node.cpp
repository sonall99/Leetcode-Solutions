class TreeAncestor {
public:
int row;
int col;
vector<vector<int>>up;
    TreeAncestor(int n, vector<int>& parent) {
        row=n;
        col=log2(n)+1;
        up.resize(row,vector<int>(col,-1));

        for(int i=0;i<n;i++){
            up[i][0]=parent[i];

        }
        for(int j=1;j<col;j++){
            for(int node=0;node<row;node++){
                if(up[node][j-1]!=-1){
                    up[node][j]=up[up[node][j-1]][j-1];
                }
            }
        }
        
    }

    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<col;j++){
            if(k &(1<<j)){ // means it is set bit
               node=up[node][j];
               if(node==-1) return -1  ;
            }

        }
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */