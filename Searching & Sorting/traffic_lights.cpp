#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll p, n;
    cin >> p >> n;

    vector<ll> nums(n);

    for(ll i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<ll> lights;
    multiset<ll> lengths;

    lights.insert(0);
    lights.insert(p);

    lengths.insert(p);

    for(ll i = 0; i < n; i++) {

        ll x = nums[i];

        auto it = lights.upper_bound(x);

        ll right = *it;

        --it;
        ll left = *it;

        // Remove the old segment
        lengths.erase(lengths.find(right - left));

        // Add the two new segments
        lengths.insert(x - left);
        lengths.insert(right - x);

        // Insert new traffic light
        lights.insert(x);

        cout << *lengths.rbegin() << " ";
    }

    return 0;
}