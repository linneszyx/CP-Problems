
bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0) return true;
        }
        
        bool ans = false;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(mp.find(sum)!=mp.end()||sum == 0){
                ans = true;
                break;
            }
            mp[sum]++;
        }
        return ans;
    }
