class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l[n];
        int c=0;
        int ans=INT_MIN;
        int r[n];
        for(int i=0;i<n;i++){
            ans=max(ans,height[i]);
            l[i]=ans;

        }
        ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,height[i]);
            r[i]=ans;

        }
        for(int i=0;i<n;i++){
            c+=min(l[i],r[i])-height[i];
        }
        return c;

        
    }
};