#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int i = 0; 
    int j = 0;

    set<int> s;
    long long ans = 0;
    
    while(j < n){
        if(s.count(nums[j]) == 0){
            s.insert(nums[j]);
            ans = max(ans, (long long)(j - i + 1));
        }
        else{
            while(s.find(nums[j]) != s.end()){
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            ans = max(ans, (long long)(j - i + 1));
        }
        j++;
    }

    cout << ans;
    return 0;
}