class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int c=0;
        while(i<s.size()){
            while(j<t.size()){
                if(t[j]==s[i]) {
                    c++;
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
        return (s.size()==c)?true:false;
        
    }
};