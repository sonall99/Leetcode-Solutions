class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && isspace(s[i])) {
                i++;
            }
            string word = "";
            while (i < s.size() && !isspace(s[i])) {
                word += s[i];
                i++;
            }

            if (!word.empty()) {
                words.push_back(word);
            }
        }
        if (words.size() != pattern.size())
            return false;
        map<char,string> mp;
        map<string,char> mp2;
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=words[i] ||( mp2.find(words[i])!=mp2.end() && mp2[words[i]] !=pattern[i])) return false;
            mp[pattern[i]]=words[i];
            mp2[words[i]]=pattern[i];
        }
        return true;
    }
};