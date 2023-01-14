#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void wafifuuuuui(){
    ll nax;
    cin>>nax;
    ll polxzc[2*nax];
    for (int i = 0; i < 2*nax; i++)
    {
        cin>>polxzc[i];
    }
    vector<ll> zpxo,zpxc;
    for (ll i = 0; i < nax; i++)
    {
        if(polxzc[i]>nax){
            zpxo.push_back(i);
        }
    }
    for (ll i = nax; i < 2*nax; i++)
    {
        if(polxzc[i]<=nax){
            zpxc.push_back(i);
        }
    }
    ll ressds = 0;
    for (ll i = 0; i < zpxo.size(); i++)
    {
        ressds += (zpxc[i]-zpxo[i]);
    }
    cout<<ressds<<"\n";   
}
int main()
{
    int TC;
    cin>>TC;
    while (TC--)
    {
        wafifuuuuui();
    }
    
return 0;
}