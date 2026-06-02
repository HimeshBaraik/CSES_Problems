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
    ll n;
    cin >> n;

    vector<ll> nums(n);
    for(ll i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    ll ts = 0;
    for(ll& x : nums){
            ts += x;
    }

    ll cost = 0;
    ll cs = 0;
    ll k = 0;
    ll ans = INF;
    for(ll & x : nums){
        cs = cs+x;
        k++;
        
        cost = k*x - cs + (ts - cs) - (n-k)*x;
        ans = min(ans, cost);
    }
    cout << ans << endl;
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