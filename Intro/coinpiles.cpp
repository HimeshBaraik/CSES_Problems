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



// logic for one test case:
void solve(){
    ll a, b;
    cin>>a>>b;
    
    if(2*a >= b && ((2*a - b) % 3 == 0) && (2*b - a) >= 0 && (2*b - a)%3 == 0){
        yes;
        return;
    }

    no;
}

// main handles test cases
int main(){
    fast_io;

    int t=1;
    cin>>t; // uncomment if multiple test cases
    while(t--){
        solve();
    }

    return 0;
}