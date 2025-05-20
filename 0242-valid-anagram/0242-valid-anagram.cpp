class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;
        for(auto i:s){
            mp1[i]++;
        }
        for(auto i:t){
            mp2[i]++;
        }
        for(auto i:mp1){
            if(mp2[i.first]!=i.second) return false;
        }
        for(auto i:mp2){
            if(mp1[i.first]!=i.second) return false;
        }

        return true;
    }
};