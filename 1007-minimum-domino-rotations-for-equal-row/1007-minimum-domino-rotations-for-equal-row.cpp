class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> mp1, mp2;
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != bottoms[i]) {
                mp1[tops[i]]++;
                mp2[bottoms[i]]++;
                mp2[tops[i]]++;
                mp1[bottoms[i]]++;
            } else {
                mp1[tops[i]]++;
                mp2[tops[i]]++;
            }
        }

        vector<int> values;
        int mini = INT_MAX;
        for (auto& [val, freq] : mp1) {
            if (freq == n) {
                values.push_back(val);
            }
        }

        for (auto& val : values) {
            int cnt = 0;
            for (auto& i : tops) {
                if (val != i) cnt++;
            }
            mini = min(mini, cnt);
        }

        return mini == INT_MAX ? -1 : mini;
    }
};
