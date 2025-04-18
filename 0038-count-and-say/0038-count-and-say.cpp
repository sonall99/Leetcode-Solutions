class Solution {
    string rle(string nums){
        string s="";
        int i=0,n=nums.size();
        while(i<n){
            int c=1;
            while((i+1)<n && nums[i]==nums[i+1]){
                c++;
                i++;
            }
            s+=to_string(c)+nums[i];
            i++;
        }
        return s;

    }
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;
        for(int i=0;i<n-1;i++){
            ans=rle(ans);

        }
        return ans;
    }
};