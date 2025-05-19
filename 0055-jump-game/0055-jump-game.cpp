class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy
        int maxreach=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxreach) return false;
            maxreach=max(maxreach,i+nums[i]);
            if(i==n-1) return true;
        }
        return true;
    }
};