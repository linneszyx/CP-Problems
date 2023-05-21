#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int n;
  cin>>n;
  int t,c;
  int count=0;
  for(int i=1;i<=n;i++){
    cin>>t>>c;
    if(c-t<=1){
      continue;
    }
    count++;
  }
  cout<<count<<endl;
  return 0;
}