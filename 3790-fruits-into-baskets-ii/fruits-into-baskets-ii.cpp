class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        unordered_set<int> st; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(baskets[j] >= fruits[i]){
                    if(st.find(j) != st.end()){
                    }
                    else{
                    st.insert(j);
                    break;
                    }
                }
            }
        }
        return m-st.size();
    }
};