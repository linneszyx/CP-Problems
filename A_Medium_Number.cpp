/*
Author : linneszyx
The King Of The Pirates : next level
*/
#include <bits/stdc++.h>
using namespace std;
void waifuuuuu(){
    
    vector<int> v;
    for(int i=0; i<3;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    cout<<v[1]<<endl;
}
int main()
{ ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        waifuuuuu();
    }
    return 0;
}