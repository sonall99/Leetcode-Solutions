class FoodRatings {
public:
unordered_map<string,int>mp1;
unordered_map<string,set<pair<int,string>>>mp2;
unordered_map<string,string>mp3;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp1[foods[i]]=ratings[i];
            mp2[cuisines[i]].insert({-ratings[i],foods[i]});
            mp3[foods[i]]=cuisines[i];
        }
        
    }

    void changeRating(string food, int newRating) {
        for(auto i:mp1){
            if(i.first==food) {
                i.second=newRating;
                string cui =mp3[food];
                int old=mp1[food];
                mp2[cui].erase({-old,food});
                mp2[cui].insert({-newRating,food});
            }
        }
        
    }
    
    string highestRated(string cuisine) {
        string ans=mp2[cuisine].begin()->second;
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */