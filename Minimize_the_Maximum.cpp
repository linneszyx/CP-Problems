
#include<bits/stdc++.h>
using namespace std;
#define xx long long int
bool isMatched(vector<xx> victor,xx mid_term){
    int size_of_victor = victor.size();
    for(int xp = size_of_victor-1;xp>0;xp--){
        if(victor[xp]>mid_term){
            victor[xp-1] += victor[xp]-mid_term;
        }
    }
    if(victor[0]>mid_term){
        return false;
    }
    else{
        return true;
    }
}
void waifuuuuio(){
    int n;
   cin>>n;
    vector<xx> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    xx sum_of_vic = 0;
    xx maxi_of_vic = 0;
    for (int i = 0; i < n; i++)
    {
        maxi_of_vic = max(maxi_of_vic,vec[i]);
    }
    xx s =0;
    xx e = maxi_of_vic;
    xx res = maxi_of_vic;
    while(s<=e){
        xx m = (s+e)/2;
        if(isMatched(vec,m)){
            e = m-1;
            res = m;
        }
        else{
            s = m+1;
        }
    }
    cout<<res<<"\n";
    
}
int32_t main()
{
    int tpx;
    cin>>tpx;
    while (tpx--)
    {
        waifuuuuio();
    }
    
return 0;
}