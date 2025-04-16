class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        int res=0,i=0,j=0;
        int pair=0;
        while(j<n){
            pair+=mp[nums[j]];
            mp[nums[j]]++;
            while(i<n &&pair>=k){
                res+=n-j;
                mp[nums[i]]--;
                pair-=mp[nums[i]];
                i++;
            }
            j++;


        }
        return res;

    }
};