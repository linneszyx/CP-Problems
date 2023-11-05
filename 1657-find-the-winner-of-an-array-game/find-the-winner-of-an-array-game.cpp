class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int me = arr[0];
        queue<int> q;
        for(int i=1;i<arr.size();i+=1){
            me = max(me,arr[i]);
            q.push(arr[i]);
        }
        int c = arr[0];
        int ws = 0;
        while(!q.empty()){
            int op = q.front();
            q.pop();
            if(c>op){
                q.push(op);
                ws+=1;
            }
            else {
                q.push(c);
                c = op;
                ws=1;
            }
            if(ws==k || c==me) return c;
        }
        return -1;
    }
};