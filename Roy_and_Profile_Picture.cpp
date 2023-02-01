#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,n;
    cin>>l;
    cin>>n;
    int w[n],h[n];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>h[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(w[i]<l || h[i]<l) {
            cout<<"UPLOAD ANOTHER\n";
        }
        else {
            if(w[i]==h[i])
            {
                cout<<"ACCEPTED\n";
            }
            else{
                cout<<"CROP IT\n";
            }
        }
    }  
return 0;
}