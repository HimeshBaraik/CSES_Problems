// Includes all the standard headers
#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// constants:
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244853; // 1e9 + 7;

// common definitions:
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

//helpers:
void print_v(vector<ll>& v){
    for(ll& x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}

unordered_set<string> permutations; // to store unique permutations

// store all permutaions in set and in main sortg them in alphabetical order and print them
void solve(string res, string cs, int index, int n){
    if(index == n){
        permutations.insert(res);
        return;
    }

    for(string::size_type i = 0; i < cs.size(); i++){
        // pick the character at index i and add it to result and remove it from cs and call solve for remaining characters
        char c = cs[i];
        string new_cs = cs.substr(0, i) + cs.substr(i + 1);
        solve(res + c, new_cs, index + 1, n);
    }

}

// main handles test cases
int main(){
    fast_io;

    int t=1;
    // cin>>t; // uncomment if multiple test cases
    while(t--){
        string s;
        cin>>s;
        solve("", s, 0, s.size()); 
        // sort and print unique permutations
        vector<string> sorted_perms(permutations.begin(), permutations.end());
        sort(sorted_perms.begin(), sorted_perms.end());
        cout << sorted_perms.size() << endl;
        for(const string& perm : sorted_perms){
            cout << perm << endl;
        }
        permutations.clear(); // clear the set for the next test case
    }

    return 0;
}