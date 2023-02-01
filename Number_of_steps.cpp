#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];     
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];     
    }
   int mini = a[0];
   for (int i = 0; i < n; i++)
   {
     mini = min(mini,a[i]);
   }
   int i=0,s=0;
   while(i<n){
    while(a[i]>mini){
        a[i]=a[i]-b[i];
        s++;
    }
    if(a[i]<mini){
        mini = a[i];
        if(i==n-1){
            s=-1;
            break;
        }
    }
    else if(a[i]<0){
        s = -1;
        break;
    }
    else
    {
        i++;
    }
    
   }
    
    cout<<s<<endl;
    
return 0;
}