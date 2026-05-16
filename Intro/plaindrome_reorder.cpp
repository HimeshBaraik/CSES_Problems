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


// logic for one test case:
void solve(){
    string s;
    cin>>s;

    vector<int> freq(26, 0);
    for(char& c: s){
        freq[c - 'A']++;
    }

    if(s.size() % 2 == 0){
        for(int& f: freq){
            if(f % 2 == 1){
                cout << "NO SOLUTION";
                return;
            }
        }
    } else {
        int odd_count = 0;
        for(int& f: freq){
            if(f % 2 == 1){
                odd_count++;
            }
        }
        if(odd_count != 1){
            cout << "NO SOLUTION";
            return;
        }
    }
    // make the palindrome:
    string left_half = ""; 
    char middle_char = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 == 1){
            middle_char = 'A' + i;
        }
        left_half += string(freq[i] / 2, 'A' + i);
    }
    string right_half = left_half;
    reverse(right_half.begin(), right_half.end());
    cout << left_half;
    if(middle_char != 0) cout << middle_char;
    cout << right_half << endl;
}

// main handles test cases
int main(){
    fast_io;

    int t=1;
    // cin>>t; // uncomment if multiple test cases
    while(t--){
        solve();
    }

    return 0;
}