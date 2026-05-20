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
    ll n;
    cin>>n;
    
    // prepare the 2D grid of size n x n
    vector<vector<ll>> grid(n, vector<ll>(n, 0));

    // initialize first row and first column
    for(ll i = 0; i < n; i++){
        grid[i][0] = i;
        grid[0][i] = i;
    }

    // fill the rest of the grid by computing mex over the union of the values
    // in the current row to the left and current column above
    for(ll i = 1; i < n; i++){
        for(ll j = 1; j < n; j++){
            unordered_set<ll> seen;
            for(ll k = 0; k < i; k++){
                seen.insert(grid[k][j]);
            }
            for(ll k = 0; k < j; k++){
                seen.insert(grid[i][k]);
            }

            ll mex = 0;
            while(seen.find(mex) != seen.end()){
                mex++;
            }
            grid[i][j] = mex;
        }
    }

    // print the grid
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
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