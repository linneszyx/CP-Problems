class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for(int i=1;i<n;i+=1) pre[i]=pre[i-1]^arr[i];
        vector<int> res(queries.size());
        for(int k=0;k<queries.size();k+=1){
            int i = queries[k][0];
            int j = queries[k][1];
            if(i==0) res[k]=pre[j];
            else res[k]=pre[j]^pre[i-1];
        }
        return res;
    }
};