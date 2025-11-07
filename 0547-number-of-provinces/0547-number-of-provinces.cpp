class Solution {
public:
void dfs(int node, vector<vector<int>>&v, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < v.size(); i++) {
            if (v[node][i] && !visit[i]) {
                dfs(i, v, visit);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        int num= 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                num++;
                dfs(i, v, visit);
            }
        }

        return num;
    }
};