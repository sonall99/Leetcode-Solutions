class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>v(26,0);
        for(char c:brokenLetters){
            int ind=c-97;
            v[ind]=true;
        }
        int c=0;
        stringstream ss(text);
        string word;
        while (ss >> word){
            bool f=true;
            for(int j:word){
                if(v[j-97]==true) f=false;
            }
            if(f) c++;
        }
        return c;
    }
};