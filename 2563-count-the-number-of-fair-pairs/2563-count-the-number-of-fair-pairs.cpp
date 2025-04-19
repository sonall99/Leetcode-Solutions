class Solution {
public:
    int n;
    long long cnt(vector<int>& nums, int x){
        int left = 0, right = n - 1;
        long long ans = 0;
        while(left < right){
            int s = nums[left] + nums[right];
            if (s < x){
                ans += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        return cnt(nums, upper + 1) - cnt(nums, lower);
    }
};