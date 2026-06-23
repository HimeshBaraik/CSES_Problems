#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    long long cs = 0;
    long long ans = 0;
    for(long long & x: nums){
        cs=cs+x;
        if(cs<0){
            cs = 0;
        }
        else{
            ans = max(ans, cs);
        }
    }

    if(ans == 0){
        ans = INT_MIN;
        for(long long& x: nums){
            ans = max(ans, x);
        }
    }

    cout<<ans;
    return 0;
}