class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char c: s){
            if(c=='*' && !result.empty()){
                result.pop_back();
            }
            else if(c=='#'){
                result+=result;
            }
           else if(c=='%'){
            reverse(result.begin(), result.end());
           }
           else if(c!='*'&& c!='#'&& c!='%') result+=c;
        }
        return result;
    }
};