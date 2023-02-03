/*
Author : linneszyx
*/
#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[],int n)
{
    int temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<arr[1]<<endl;
    

}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}