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
    cin>>n;

    ll sum = 0;
    sum = n*(n+1)/2;
    if(sum % 2 == 1){
        no;
        return;
    }

    vector<ll> set1, set2;
    ll target = sum / 2;
    for(ll i = n; i >= 1; i--){ 
        if(target - i >= 0){
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    yes;
    cout << set1.size() << endl;
    print_v(set1);
    cout << set2.size() << endl;
    print_v(set2);
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