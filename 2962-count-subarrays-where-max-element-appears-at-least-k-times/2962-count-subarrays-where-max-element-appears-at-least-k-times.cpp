class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int maxele = *max_element(nums.begin(), nums.end());
        int i = 0, j = 0, cnt = 0;
        while(j<n){
            if(nums[j] ==  maxele) cnt++;
            while(i<=j && cnt >= k){
                ans += (n - j);
                if(nums[i] == maxele) cnt--;
                i++;
            }
            j++;
        }

        return ans;
    }
};