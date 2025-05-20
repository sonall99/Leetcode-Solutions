class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int i=0,j=numbers.size()-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                return v={i+1,j+1};
            }
            else if (sum>target) j--;
            else i++;
        }
        return v;
    }
};