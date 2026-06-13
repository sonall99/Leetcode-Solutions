class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &word:words){
            int len=0;
            for(char c:word){
                len+=weights[c-'a'];
            }
            len=len%26;
            ans+=('z'-len);


        }
        return ans;
    }
};