class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int ele=0;
        for(int i=0;i<n;i++){
            if(c==0) {
                ele=nums[i];
                c=1;
            }
            else if(nums[i]==ele){
                c++;
            }
            else c--;

        }
        int e=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                e++;
            }
        }
        return ele;
        return 0;

        
        
    }
};