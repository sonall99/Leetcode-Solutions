class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid[0].size();
        unordered_map<int,priority_queue<int>>maxheap;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>minheap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=i-j;
                if(val>=0){
                    maxheap[val].push(grid[i][j]);
                }
                else{
                    minheap[val].push(grid[i][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=i-j;
                if(val>=0){
                    grid[i][j]=maxheap[val].top();
                    maxheap[val].pop();
                }
                else{
                    grid[i][j]=minheap[val].top();
                    minheap[val].pop();
                }
            }
        }
        return grid;

    }
};