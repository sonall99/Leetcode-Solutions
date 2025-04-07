class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        int ret;
        ss >> ret;


        return ret;

    }
};