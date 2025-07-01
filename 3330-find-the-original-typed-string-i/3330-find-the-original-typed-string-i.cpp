class Solution {
public:
    int possibleStringCount(string word) {
        map<char,int>mp;
        for(char& a: word){
            mp[a]++;
        }
        int c=0;
        for(auto i:mp){
            c+=i.second-1;
        }
        return c+1;

    }
};