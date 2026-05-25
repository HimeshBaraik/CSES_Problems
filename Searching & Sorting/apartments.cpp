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
    cin>>k;
    
    vector<int> a(n,0);
    for(int i = 0; i < a.size(); i++){
        cin>>a[i];
    }
    
    vector<int> b(m,0);
    for(int i = 0; i < b.size(); i++){
        cin>>b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0;
    int j = 0;
    
    int ans = 0;
    
    while(i < a.size() && j < b.size()){
        if(abs(a[i] - b[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else{
            if(a[i] < b[j]){
                i++;
            }
            else{
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