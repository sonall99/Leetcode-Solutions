class Solution {
public:
    vector<pair<int,int>> serve = {{4,0},{3,1},{2,2},{1,3}}; 
    vector<vector<double>> dp;

    double solve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        if (dp[A][B] != -1.0) return dp[A][B];

        double prob = 0.0;
        for (auto &p : serve) {
            prob += solve(A - p.first, B - p.second);
        }
        return dp[A][B] = 0.25 * prob;
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0;  
        int scaledN = (n + 24) / 25; 
        dp.resize(scaledN + 1, vector<double>(scaledN + 1, -1.0));
        return solve(scaledN, scaledN);
    }
};