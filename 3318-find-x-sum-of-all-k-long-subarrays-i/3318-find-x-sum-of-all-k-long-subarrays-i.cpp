class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        while(k<=n){
            for(int i=0;i<k;i++){
                unordered_map<int,int>mp;
                mp[nums[i]]++;
            }
            vector<pair<int,int>>v;
            for(auto i:mp){
                v.push_back({i.second,i.first});
            }
            sort(v.begin(),v.end(),greater<pair<int,int>>());
            
            int xsum=0;
            for(int i=0;i<x;i++){
                xsum+=v[i].first*v[i].second;
            }
            ans.push_back(xsum);
            k++;
        }
    }
};