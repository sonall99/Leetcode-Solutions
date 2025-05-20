class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 &&nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
           int  k=n-1;
            while(j<k){
                vector<int>v;
                int sum=nums[i]+ nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    v={nums[i],nums[j],nums[k]};
                    j++;
                    ans.push_back(v);
                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }

        }
        return ans;
    }
};