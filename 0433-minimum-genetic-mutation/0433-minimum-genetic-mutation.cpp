class Solution {
public:
//O(m^n *m*n)
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>s(bank.begin(),bank.end());
        queue<string>q;
        q.push(startGene);
        set<string>visited;
        int level=0;
        while(!q.empty()){
        int size=q.size();
        while(size--){
            string curr_str=q.front();
            if(curr_str==endGene) return level;
            q.pop();
            for(char ch:"ACGT"){
                for(int i=0;i<8;i++){
                    string temp=curr_str;
                    temp[i]=ch;
                    if(visited.find(temp)==visited.end() && s.find(temp)!=s.end()){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
        }
        level++;
        }
        return -1;
    }
};

