#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int c1 = 0;
    int c2 = 0;
    int n = str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='z')
        {
            c1++;
        }
        else{
            c2++;
        }
    }
    if(c2==c1*2) cout<<"Yes\n";
    else cout<<"No\n";



return 0;
}