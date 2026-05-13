//------------------------------------------------------------
// Sliding Window Xor
//------------------------------------------------------------


// Includes all the standard headers
#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// constants:
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244853; // 1e9 + 7;

// common definitions:
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

//helpers:
void print_v(vector<ll>& v){
    for(ll& x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}


// logic for one test case:
void solve(){
    ll n,k,x,a,b,c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<ll> v;
    for(int i = 0; i < n; i++){
        v.push_back(x);
        x = (a*x + b)%c;
    }

    // printing vector
    // print_v(v);

    int i = 0;
    int j = 0;

    ull ans=0;
    ull xr=0;

    while(j < n){
        //processing:
        xr = xr^v[j];

        //
        if(j-i+1 < k){
            j++;
        }
        else{
            if(j-i+1 == k){
                ans=ans^xr;

                // calculate and move
                xr = xr^v[i];
                i++;
                j++;
            }
        }
    }

    cout<<ans;
}

// main handles test cases
int main(){
    fast_io;

    int t=1;
    // cin>>t; // uncomment if multiple test cases
    while(t--){
        solve();
    }

    return 0;
}