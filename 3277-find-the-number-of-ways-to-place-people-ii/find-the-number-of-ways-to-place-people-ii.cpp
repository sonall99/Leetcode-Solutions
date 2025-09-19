class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points) , end(points) , [](const auto& a , const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int cntPairs = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int aliceY = points[i][1] , last = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int bobY = points[j][1];
                if (aliceY >= bobY && bobY > last) {
                    last = bobY;
                    cntPairs++;
                }
            }
        }
        return cntPairs;
    }
};