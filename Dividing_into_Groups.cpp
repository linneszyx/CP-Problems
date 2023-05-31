#include<bits/stdc++.h>
using namespace std;
vector<int> rem(vector<int>& lst) {
    lst.erase(remove(lst.begin(), lst.end(), 0), lst.end());
    return lst;
}

int sol(vector<int>& a, int k) {
    if (k > a.size()) {
        return 0;
    }
    
    int ct = a[k - 1];
    
    for (int i = 0; i < k; i++) {
        a[i] -= a[k - 1];
    }
    
    a = rem(a);
    
    return ct + sol(a, k);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        
        for (int j = 0; j < n; j++) {
           cin >> a[j];
        }
        
       sort(a.begin(), a.end(),greater<int>());
        
        cout << sol(a, k) << endl;
    }
    
    return 0;
}