class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        if(haystack==needle) return 0;
         if (n == 0) return 0;
        int m=haystack.length();
        for(int i=0;i<=m-n;i++){
            if(haystack.substr(i,n)==needle) return i;
        }
        return -1;
    }
};