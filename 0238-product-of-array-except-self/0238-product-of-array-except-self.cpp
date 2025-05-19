class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int r=1;
        for(int i=0;i<n;i++){
            v[i]=r;
            r*=nums[i];
            
        }
        int l=1;
        for(int j=n-1;j>=0;j--){
            v[j]=l*v[j];
            l*=nums[j];
        }
        return v;
        
    }
};