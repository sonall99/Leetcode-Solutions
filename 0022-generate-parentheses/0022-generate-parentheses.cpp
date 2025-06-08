class Solution {
    vector<string>ans;
    bool is_valid(string s){
        int c=0,i=0;
        while(i<s.length()){
            if(s[i]=='(')c++;
            else{
                c--;
                if(c<0) return false;
            }
            i++;
        }
        return c==0;
    }
public:
    void parenthesis(int ind,int n,string s){
        if(ind>n)return;
        if(ind==n){
            if(is_valid(s))ans.push_back(s);
            return;

        }
        s.push_back('(');
        parenthesis(ind+1,n,s);
        s.pop_back();
        s.push_back(')');
        parenthesis(ind+1,n,s);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
    parenthesis(0,n*2,s);
        return ans;
    }
};