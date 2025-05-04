class Solution {
    private:
    void combi(int i,int tar,vector<int>& arr,vector<int>&ds,vector<vector<int>>&ans){
        if(i==arr.size()){
            if(tar==0) ans.push_back(ds);
            return;

        }
        if(tar>=arr[i]){
            ds.push_back(arr[i]);
            combi(i,tar-arr[i],arr,ds,ans);
            ds.pop_back();

        }
        combi(i+1,tar,arr,ds,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combi(0,target,candidates,ds,ans);
        return ans;

        
    }
};