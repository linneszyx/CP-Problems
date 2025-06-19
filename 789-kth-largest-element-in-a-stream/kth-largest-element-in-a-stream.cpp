class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for(auto x : nums) pq.push(x);
    }
    
    int add(int val) {  
        pq.push(val);
        while(pq.size() > s) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */