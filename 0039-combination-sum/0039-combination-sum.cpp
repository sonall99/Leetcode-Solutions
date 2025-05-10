class Solution {
    void combi(int ind,vector<int>& candidates, int target,vector<int>&ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if (ind == candidates.size()) return;
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            combi(ind, candidates, target - candidates[ind], ds, ans);
            ds.pop_back();
        }
        combi(ind+1,candidates,target,ds,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combi(0,candidates,target,ds,ans);
        return ans;

        
    }
};