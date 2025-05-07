class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int ans=0;
        int row=moveTime.size();
        int col=moveTime[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        vis[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int t=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            ans+=t+1;
            if(r==row-1 && c==col-1) return ans;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<row &&nc>=0 && nc<col&& !vis[nr][nc]){
                    q.push({t,{nr,nc}});
                    vis[nr][nc]=1;
                }

            }

            
        }
        return ans;

    }
};