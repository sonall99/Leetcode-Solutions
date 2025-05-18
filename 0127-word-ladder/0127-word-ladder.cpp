class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        int level=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front();
                q.pop();
                if(word==endWord) return level;
                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<word.size();i++){
                        string new_word=word;
                        new_word[i]=ch;
                        if(st.find(new_word)!=st.end()){
                            q.push(new_word);
                            st.erase(new_word);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};