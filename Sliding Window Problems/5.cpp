#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Fast I/O
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Print helper
void print_v(const vector<ll>& v){
    for(ll x: v) cout << x << " ";
    cout << "\n";
}

// Solve one test case
void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    unordered_map<ll,int> mp;
    vector<ll> ans;
    int i = 0;

    for(int j = 0; j < n; j++){
        // Add current element to the map
        mp[v[j]]++;

        // Remove element that is leaving the window
        if(j - i + 1 > k){
            mp[v[i]]--;
            if(mp[v[i]] == 0) mp.erase(v[i]);
            i++;
        }

        // Window of size k: record distinct count
        if(j - i + 1 == k){
            ans.push_back(mp.size());
        }
    }

    print_v(ans);
}

int main(){
    fast_io;

    int t = 1;
    // cin >> t; // uncomment for multiple test cases
    while(t--) solve();

    return 0;
}
