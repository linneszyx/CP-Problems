#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int s = 0;
    int e = str.length()-1;
    bool flag = true;
    while (s<=e)
    {
        if(str[s++]!=str[e--]){
            flag =false;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    
    
return 0;
}