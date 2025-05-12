class Solution {
    vector<vector<int>> dp;

    int solve(const string &s, const string &t, int i, int j, int n, int m) {
        if (i >= n || j >= m) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = 1 + solve(s, t, i + 1, j + 1, n, m);
        } else {
            int case1 = solve(s, t, i + 1, j, n, m);
            int case2 = solve(s, t, i, j + 1, n, m);
            return dp[i][j] = max(case1, case2);
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Initialize dp table with -1
        dp.assign(n, vector<int>(m, -1));

        return solve(text1, text2, 0, 0, n, m);
    }
};
