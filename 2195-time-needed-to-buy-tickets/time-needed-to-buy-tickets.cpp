class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t = 0;
        for(int i=0;i<tickets.size();i+=1){
            if(i<=k) t+=min(tickets[i],tickets[k]);
            else t+=min(tickets[i],tickets[k]-1);
        }
        return t;
    }
};