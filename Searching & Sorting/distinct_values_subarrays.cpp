#include<bits/stdc++.h>

using namespace std;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

void solve(){
    ll n;
    cin>>n;

    vector<int> nums(n,0);

    for(ll i =0; i < n; i++){
        cin>>nums[i];
    }

    int i = 0;
    int j = 0;

    unordered_set<ll> s;
    ll ans = 0;

    while (j < nums.size()) {
        if (s.find(nums[j]) == s.end()) {
            s.insert(nums[j]);

            ans += (j - i + 1);
            j++;
        }
        else {
            s.erase(nums[i]);
            i++;
        }
    }

    cout << ans;

}

int main(){
    solve();
    return 0;
}