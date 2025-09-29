class Solution {
    int solve(vector<int>&values,int i,int j){
        if(j-i+1<3) return 0;
        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            int sum=values[i]*values[j]*values[k]+solve(values,i,k)+solve(values,k,j);
            result=min(result,sum);
           
        }
        return result;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        return solve(values,0,n-1);
    }
};