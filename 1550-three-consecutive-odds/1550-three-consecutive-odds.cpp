class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int arr_size=arr.size();
        int c=0;
        for(int i=0;i<arr_size;i++){
            if(c>=3) return true;
            if(arr[i]%2==0) c=0;
            else{
                c++;
            }
        }
         if(c>=3) return true;

        return false;
        
    }
};