class CustomStack {
public:
    int n;
    stack<int> st;
    vector<int> inc;
    CustomStack(int n) {
        this->n=n;
    }
    
    void push(int x) {
        if(st.size()<n){
            st.push(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        if(inc.size()>1) inc[inc.size()-2]+=inc.back();
        int res=st.top()+inc.back();
        st.pop();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        if(!st.empty()) {
            int idx = min(k,(int)inc.size())-1;
            inc[idx]+=val;
        }
    }
};
