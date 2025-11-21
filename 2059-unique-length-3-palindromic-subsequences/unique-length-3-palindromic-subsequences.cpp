class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }

        int totalPalindrome = 0;
        set<char> used;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(used.count(ch)) continue;
            used.insert(ch);
            if(mp[ch].size() < 2) continue;

            auto &idx = mp[ch];
            int first = idx[0];
            int last  = idx.back();
            set<char> mid;
            for(int k = first + 1; k < last; k++){
                mid.insert(s[k]);
            }

            totalPalindrome += mid.size();
        }

        return totalPalindrome;
    }
};
