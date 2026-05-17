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
vector<string> solve(int n){

    // for n-1
    vector<string> res;
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    vector<string> prev = solve(n-1);
    for(string& s: prev){
        res.push_back("0" + s);
    }
    for(int i = prev.size() - 1; i >= 0; i--){
        res.push_back("1" + prev[i]);
    }
    return res;
}

// main handles test cases
int main(){
    fast_io;

    int t=1;
    // cin>>t; // uncomment if multiple test cases
    while(t--){
        int n;
        cin >> n;
        vector<string> result = solve(n);
        for(const string& s: result){
            cout << s << endl;
        }
    }           
    return 0;
}
