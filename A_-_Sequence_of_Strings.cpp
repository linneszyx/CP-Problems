#include<bits/stdc++.h>
using namespace std;
bool comp(string s1,string s2){
    return s1>s2;
}
int main()
{
    int n;
    cin>>n;
    string s1[n];
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int i=n-1;i>=0;i--){
        cout<<s1[i]<<endl;
    }
return 0;
}