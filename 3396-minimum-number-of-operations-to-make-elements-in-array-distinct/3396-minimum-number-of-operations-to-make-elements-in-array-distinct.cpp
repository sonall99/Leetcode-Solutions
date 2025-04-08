class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int b=0,c=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(mp[nums[i]]==1){
                b=i+1;
                c=1;
                break;}
            else mp[nums[i]]++;
            }
        if(c==0) return 0;
        int ans=b/3;
        if(b%3>0) ans++;
        return ans;
    }
};