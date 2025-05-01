class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int c=0;
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=tasks.size();
        int m=workers.size();
        map<int,int>mp;
        int i=0,j=0;
        while(i<=n &&j<=m){
            mp[tasks[i]]=workers[j];
            i++;
            j++;
        }
        for(auto &i:mp){
            if(i.first<=i.second) c++;
            else{
                if(pills>0){
                    int u=i.first;
                    u+=strength;
                    pills=pills-1;
                    if(u<=i.second) c++;
                }

            }
        }
        return c;
        


        
    }
};