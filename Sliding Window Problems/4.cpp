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
    ll n,k,x,a,b,c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<ll> v;
    for(int i = 0; i < n; i++){
        v.push_back(x);
        x = (a*x + b)%c;
    }

    // precompute suffix and prifix  or:
    vector<ll> por;
    vector<ll> sor;

    ll qq = 0;
    ll ww = 0;
    for(int i = 0; i < n; i++){
        qq = qq |v[i];
        por.push_back(qq);
        ww = ww |v[n-i-1];
        sor.push_back(ww);
    }
    ll comp_or = por.back();

    ll ans = 0;
    ll curr_or = 0;

    int i = 0;
    int j = 0;
    while(j < n){
        if(i == 0){
            curr_or = curr_or|v[j];
        }
        else{
            if(j == n-1){
                curr_or = comp_or & (~por[i-1]);
            }
            else{
                curr_or = comp_or & (~(por[i-1] |sor[j+1]));
            }
        }
        

        if(j-i+1 < k){
            j++;
        }
        else{
            if(j-i+1 == k){
                ans=ans^curr_or;
                i++;
                j++;
            }
        }
    }

    cout<<ans;
}

int main(){
    fast_io;

    int t = 1;
    // cin >> t; // uncomment for multiple test cases
    while(t--) solve();

    return 0;
}
