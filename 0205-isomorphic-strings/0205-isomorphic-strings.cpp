class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp1;
       map<char,char>mp2;
        int c1=0,c2=0;
        for(int i=0;i<s.length();i++){
            if((mp1.find(s[i])!=mp1.end()&& mp1[s[i]]!=t[i]) || (mp2.find(t[i])!=mp2.end()&& mp2[t[i]]!=s[i])) return false;
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};