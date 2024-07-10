class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> ps;
        for(const string &log:logs){
            if(log=="../") {
                if(!ps.empty()) ps.pop_back();
            }
            else if(log!="./") ps.push_back(log);
        }
        return ps.size();
    }
};