class Solution {
public:
bool isVowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
    return false;
}
    string sortVowels(string s) {
        string st;
        for( char c:s){
            if(isVowel(c)) st+=c;
        }
        sort(st.begin(),st.end());
        string t;
        int j=0;
        for(char c:s){
            if(isVowel(c)) {
                t+=st[j];
                j++;
            }
            else{
                t+=c;
            }
        }
        return t;

    }
};