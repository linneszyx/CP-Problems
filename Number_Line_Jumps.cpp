#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    if((v1<=v2) or ((x2-x1)%(v2-v1))) cout<<"NO\n";
    else  cout<<"YES\n";
return 0;
}