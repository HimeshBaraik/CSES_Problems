#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// constants:
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244853;

// common definitions:
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// helpers:
void print_v(vector<ll>& v) {
    for (ll& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// logic for one test case:
void solve() {
    ll n;
    cin >> n;

    vector<pair<ll,ll>> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second=i;
    }
    sort(nums.begin(), nums.end());

    ll prev_index = -1;
    ll rounds = 1;

    for(ll i = 0; i < nums.size(); i++){
        if(nums[i].second < prev_index){
            rounds++;
        }
        prev_index = nums[i].second;
    }

    cout<<rounds;
    return;

}

// main handles test cases
int main() {
    fast_io;

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}