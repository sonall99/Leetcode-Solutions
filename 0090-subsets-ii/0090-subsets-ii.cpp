class Solution {
    private:
    void subset(int ind,vector<int>&ds,vector<int>&a,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind;i<a.size();i++){
            if(ind<i && a[i]==a[i-1]) continue;
            ds.push_back(a[i]);
            subset(i+1,ds,a,ans);
            ds.pop_back();
            
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>ds;
        vector<vector<int>>ans;
        subset(0,ds,arr,ans);
        return ans;
        
    }
};