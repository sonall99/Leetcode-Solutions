class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int m = edges.size();

        if (m == 0) return 1;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> qu;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }

        int cnt = 0;
        int maxi = 1;

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            cnt++;

            dp[node][colors[node] - 'a'] += 1;

            for (auto& it : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    dp[it][i] = max(dp[it][i], dp[node][i]);
                }

                indegree[it]--;

                if (indegree[it] == 0) {
                    qu.push(it);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (indegree[i] == 0) {
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        if (cnt != n) return -1;

        return maxi;
    }
};
