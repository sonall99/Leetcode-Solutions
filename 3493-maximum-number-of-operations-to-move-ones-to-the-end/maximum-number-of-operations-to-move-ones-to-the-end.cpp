class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int c1=0;
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                ans+=c1;
                while(i<n && s[i]=='0') i++;
            }
            else {
                c1++;
                i++;
            }
        }
        return ans;
    }
};