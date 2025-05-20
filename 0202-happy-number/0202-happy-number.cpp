class Solution {
public:
int solve(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        if(n==1) return true;
        
        set<int>seen;
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            n=solve(n);
        }
        return n==1;

    }
};