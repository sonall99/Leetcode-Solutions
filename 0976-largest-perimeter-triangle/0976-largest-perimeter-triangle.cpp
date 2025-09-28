class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<=n-3;i++){
            if(nums[i+1]+nums[i+2]>nums[i]){
                maxi=max(maxi,nums[i]+nums[i+1]+nums[i+2]);
            }
        }
        if(maxi==INT_MIN) return 0;
        return maxi;


        
    }
};