class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=2;
        int n=nums.size();
        if(n<=2) return n;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[res-1] && nums[i]==nums[res-2]) continue;
            nums[res]=nums[i];
            res++;
        }
        return res;
        
    }
};