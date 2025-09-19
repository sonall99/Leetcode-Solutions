class Spreadsheet {
public:
unordered_map<string,int>mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    auto solve(string s){
        if(isdigit(s[0])) return stoi(s);
        if(mp.count(s)) return mp[s];
        else return 0;
        }
    
    int getValue(string formula) {
        formula=formula.substr(1);
        auto pos=formula.find('+');
        string left=formula.substr(0,pos);
        string right=formula.substr(pos+1);
        return solve(left)+solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */