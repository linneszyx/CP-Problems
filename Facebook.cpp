/*
Author : linneszyx
The King Of The Pirates : next level
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void waifuuuuu(){
    int n,i;
    cin>>n;
    int a[n],b[n];
    fo(i,n) cin>>a[i];
    fo(i,n) cin>>b[i];
    int idx = 0;
    int ar=0,br=0;
    fo(i,n){
        if(a[i]==ar){
            if(b[i]>=br){
                ar = a[i];
                idx = i + 1;
                br = b[i];
            }
        }
        else if(a[i]>=ar){
            ar = a[i];
            br = b[i];
            idx = i + 1;
        }
    }
    cout<<idx<<endl;
}
int main()
{ ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        waifuuuuu();
    }
    return 0;
}