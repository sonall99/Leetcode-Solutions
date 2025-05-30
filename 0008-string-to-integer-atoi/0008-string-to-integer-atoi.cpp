class Solution {
public:
    int myAtoi(string s) {
        int size=s.size();
        long num=0;
        int sign=1;
        int i=0;
        while(i<size && s[i]==' '){
            i++;
        }
        while(i<size && (s[i]=='+'||s[i]=='-')){
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
         while(i<size && isdigit(s[i])){
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')) 
                return sign==-1? INT_MIN: INT_MAX;
            num=num*10+(s[i]-'0');
            i++;
        }
        return num*sign;
    }
};