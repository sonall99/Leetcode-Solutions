class Solution {
private:
int Recursion(vector<int>&nums,int idx,int n){
    if(idx>=n)return 0;

    int take=nums[idx]+Recursion(nums,idx+2,n);
    int notTake=Recursion(nums,idx+1,n);
    return max(take, notTake);


}

public:
    int rob(vector<int>& nums) {
        return Recursion(nums,0,nums.size());
        
    }
};