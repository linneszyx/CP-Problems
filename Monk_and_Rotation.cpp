#include<bits/stdc++.h>
using namespace std;
/**
 * It rotates the array by k elements.
 * 
 * @param a the array to be rotated
 * @param k the number of rotations
 */
void rotateK(vector<int> a,int k){
int n = a.size();
k = k%n;
vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        if(i<k){
            v1.push_back(a[n+i-k]);
        }
        else{
            v1.push_back(a[i-k]);
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
     cout<<endl; 
}
/**
 * It rotates the array by k elements.
 * 
 * @return the vector v.
 */
int main()
{
    int t;
    cin>>t;
    while(t--){

    int n;
    cin>>n;
    vector<int> v;
    int k,ele;
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    rotateK(v,k);
    }
return 0;
}