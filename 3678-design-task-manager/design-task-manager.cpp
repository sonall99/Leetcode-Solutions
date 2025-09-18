class TaskManager {
public:
map<int,pair<int,int>>mp; // taskid,{userid,priority}
priority_queue<pair<int,int>>pq ;// priority,taskid
    TaskManager(vector<vector<int>>& tasks) {
        for(auto & i:tasks){
            mp[i[1]]={i[0],i[2]};
            pq.push({i[2],i[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        pq.push({priority,taskId});
        
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second=newPriority;
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        mp[taskId].second=-1;
        
    }
    
    int execTop() {
    while (!pq.empty()) {
        auto [p, i] = pq.top();
        pq.pop();
        if (mp[i].second == p) {        
            int u = mp[i].first;     
            mp[i] = {-1, -1};           
            return u;
        }
    }
    return -1; 
}

};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */