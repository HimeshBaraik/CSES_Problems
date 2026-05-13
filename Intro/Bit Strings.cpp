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
constexpr ll MOD = 1000000007; // 1e9 + 7

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

ll binaryExponentiation(ll a, ll b){
    if(b == 0) return 1;
    ll half = binaryExponentiation(a, b / 2);
    half = (half * half) % MOD;
    if(b & 1){
        half = (half * a) % MOD;
    }
    return half;
}


// logic for one test case:
void solve(){
    ll n;
    cin>>n;
    cout << binaryExponentiation(2, n) << endl;
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