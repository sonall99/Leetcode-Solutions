class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        vector<int>lmax(n,0),rmax(n,0);
        lmax[0]=nums[0];
        rmax[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i- 1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],nums[i]);
        }
        long long ans = 0;
        for(int i=1;i<n-1;i++){
            int l=lmax[i-1];
            int r=rmax[i+1];
            ans=max(ans,(1LL*(l-nums[i])*r));
        }
        return ans;


        
    }
};