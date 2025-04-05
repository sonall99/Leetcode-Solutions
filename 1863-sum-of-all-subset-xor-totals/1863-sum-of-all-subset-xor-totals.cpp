class Solution {
public:

    void solve(vector<int>& nums, int i, vector<int>& curr,vector<vector<int>>& subsets) {

        if (i == nums.size()) {
            subsets.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, i + 1, curr, subsets);
        curr.pop_back();
        solve(nums, i + 1, curr, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curr;
        solve(nums, 0, curr, subsets);
        int result = 0;
        for (auto& curr : subsets) {
            int Xor = 0;
            for (int num : curr) {
                Xor ^= num;
            }
            result += Xor;
        }
        return result;
    }
};


