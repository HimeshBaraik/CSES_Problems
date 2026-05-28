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
    int n,m,k;
    cin>>n;
    cin>>m;
    
    multiset<ll> tickets;
    for(int i = 0; i < n; i++){
        ll value;
        cin>>value;
        tickets.insert(value);
    }
    
    vector<ll> customers(m,0);
    for(int i = 0; i < m; i++){
        cin>>customers[i];
    }
    
    int j = 0;
    while(j < m){
        ll x = customers[j];
        auto itr = tickets.upper_bound(x);
        if(itr == tickets.begin()){
            cout<<-1<<endl;
            j++;
            continue;
        }
        itr--;
        cout<<*itr<<endl;
        tickets.erase(itr);
        j++;
    }
    
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