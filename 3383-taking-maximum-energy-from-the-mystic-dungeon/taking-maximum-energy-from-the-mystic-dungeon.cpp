class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = INT_MIN;
        for(int pos = energy.size()-1; pos > energy.size()-1-k; pos--){
            maxi = max(maxi , energy[pos]);
            for(int i=pos; i-k>=0; i-=k){
                energy[i-k] += energy[i];
                maxi = max(maxi , energy[i-k]);
            }
        }
        return maxi;
    }
};