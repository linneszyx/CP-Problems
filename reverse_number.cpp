#include <bits/stdc++.h>
using namespace std;
int main()
{
  //write your code here
  int n;
  cin>>n;
  int r = 0;
  int d;
  while(n!=0){
    d = n%10;
    r = r*10+d;
    n/=10;
  }
  cout<<r<<endl;
  return 0;
}