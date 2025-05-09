class Solution {
    const int m=1e9+7;
    long long  find_power(int a,int b){
        if(b==0) return 1;
        long long  value=find_power(a,b/2);
        long long result=(value*value)%m;
        if(b%2==1){
            result =(result *a)%m;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        return (long long )find_power(5,(n+1)/2)*find_power(4,(n/2))%m;
    }
};