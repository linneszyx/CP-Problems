#include <bits/stdc++.h>
using namespace std;
void is_leap(int n){
  int temp = n;
  if(temp%4==0){
    if(temp%100==0){
      if(temp%400==0){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    else{
      cout<<"Yes"<<endl;
    }
  }
  else{
  cout<<"No"<<endl;
}
  
}
int main()
{
  //write your code here
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    is_leap(n);
  }
  return 0;
}