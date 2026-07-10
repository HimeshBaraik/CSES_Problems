#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, int> mp;
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }

    long long mod = 1000000007;
    long long ans = 1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans = (ans * (it->second + 1)) % mod;
    }

    cout << (ans - 1 + mod) % mod << endl;
    return 0;
}