#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Fast I/O
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void print_v(const vector<ll>& v) {
    for (ll x : v) cout << x << " ";
    cout << "\n";
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_map<ll, int> mp;
    vector<ll> ans;
    int i = 0;

    for (int j = 0; j < n; j++) {
        mp[v[j]]++;

        // If current window size reached k
        if (j - i + 1 == k) {

            // Find mode (most frequent, smallest if tie)
            int hf = 0;
            ll mod = LLONG_MAX;

            for (auto &p : mp) {
                if (p.second > hf) {
                    hf = p.second;
                    mod = p.first;
                } else if (p.second == hf && p.first < mod) {
                    mod = p.first;
                }
            }

            ans.push_back(mod);

            // Slide window: remove v[i]
            mp[v[i]]--;
            if (mp[v[i]] == 0)
                mp.erase(v[i]);
            i++;
        }
    }

    print_v(ans);
}

int main() {
    fast_io;

    int t = 1;
    // cin >> t; // uncomment for multiple test cases
    while (t--) solve();

    return 0;
}
