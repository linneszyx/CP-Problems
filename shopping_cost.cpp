#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int quan,price;
        cin>>quan>>price;
        double final_price,t;
        if(quan>100) {
            t = (float)quan*price*0.20;
            final_price = (float)quan*price-t;
            cout<<fixed<<setprecision(1);
            cout<<final_price<<endl;
        }
        else{
            final_price = (float)quan*price;
            cout<<fixed<<setprecision(1);
            cout<<final_price<<endl;
        }
    }
return 0;
}