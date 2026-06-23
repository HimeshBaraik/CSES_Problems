#include<bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;

int main(){
    int n;
    cin>>n;

    vector<ll> nums(n);
    for(ll i = 0; i < nums.size(); i++){
        cin>>nums[i];
    }   

    multiset<ll> s;
    ll towers = 0;

    for(ll i = 0;i < nums.size(); i++){
        auto it = s.upper_bound(nums[i]);
        if(it == s.end()){
            s.insert(nums[i]);
            towers++;
        }
        else{
            s.erase(it);
            s.insert(nums[i]);
        }
    }

    cout<<towers;
    return 0;
}