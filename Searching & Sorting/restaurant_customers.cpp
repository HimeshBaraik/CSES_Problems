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
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    vector<pair<int, int>> events;

    for(pair<int, int>& p : arr){
        events.push_back({p.first, 1});
        events.push_back({p.second, -1});
    }

    sort(events.begin(), events.end(),
        [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first == b.first)
                return a.second < b.second; // -1 before +1
            return a.first < b.first;
        });

    int intersections = 0;
    int mx_intersections = 0;

    for(pair<int, int>& e : events){
        intersections += e.second;
        mx_intersections = max(mx_intersections, intersections);
    }

    cout << mx_intersections << endl;
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