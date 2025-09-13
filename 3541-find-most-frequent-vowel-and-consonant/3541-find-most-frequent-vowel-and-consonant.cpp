class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>v;
        unordered_map<char,int>c;
        for(int i=0;i<s.length();i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                v[s[i]]++;
}
            else{
                c[s[i]]++;
            }
        }
        int maxv=0,maxc=0;
        for(auto i:v){
            maxv=max(maxv,i.second);
        }
        for(auto i:c){
            maxc=max(maxc,i.second);
        }
        return maxc+maxv;
    }
};