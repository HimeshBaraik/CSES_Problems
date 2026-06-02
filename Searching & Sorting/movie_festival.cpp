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

// helper function to print a vector of long longs
void print_v(vector<ll>& v){
    for(ll& x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}



// logic for one test case:
void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> movies(n);
    for(int i=0; i<n; i++){
        cin>>movies[i].first>>movies[i].second;
    }

    // sort movies by start time
    sort(movies.begin(), movies.end());

    int endtime = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(movies[i].first >= endtime){
            count++;
            endtime = movies[i].second;
        }
        else if(movies[i].second < endtime){
            endtime = movies[i].second;
        }
    }

    cout << count << endl;
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