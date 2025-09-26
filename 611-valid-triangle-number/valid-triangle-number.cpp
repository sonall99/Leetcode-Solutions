class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(), count = 0 ;
        sort(nums.begin(), nums.end()) ;
       
        if(n<3) return 0 ;

        for(int i = n-1; i>=2; i--){
            int a = nums[i], j=i-1, k=0;
      
            while(k<j){
                if(nums[k] + nums[j] > a){
                    count+=(j-k);
                    j-- ;
                }
                else{
                    k++; 
                }
            }
        }
        return count ; 
    }
};