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


static vector<vector<int>> grid(7, vector<int>(7));

static const vector<pair<int, int>> dir = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1}   // right
};

bool isValid(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

bool blocked(int x, int y, vector<vector<int>>& grid) {
    return x < 0 || x >= 7 || y < 0 || y >= 7 || grid[x][y];
}

int countPaths(const string& s, int t, int i, int j, vector<vector<int>>& grid) {
    if (i == 6 && j == 0) {
        return t == 48;
    }

    if (t == 48) return 0;

    // PRUNING: If we are at a cell and both opposite directions are blocked, we can prune this path

    if (blocked(i - 1, j, grid) && blocked(i + 1, j, grid) &&
        !blocked(i, j - 1, grid) && !blocked(i, j + 1, grid)) {
        return 0;
    }

    if (blocked(i, j - 1, grid) && blocked(i, j + 1, grid) &&
        !blocked(i - 1, j, grid) && !blocked(i + 1, j, grid)) {
        return 0;
    }

    // If the current character is '?', we can try all 4 directions

    int ans = 0;

    if (s[t] == '?') {
        for (auto d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) && !grid[ni][nj]) {
                grid[ni][nj] = 1;
                ans += countPaths(s, t + 1, ni, nj, grid);
                grid[ni][nj] = 0;
            }
        }
    } else {
        int ni = i;
        int nj = j;
        if (s[t] == 'R') nj++;
        else if (s[t] == 'L') nj--;
        else if (s[t] == 'U') ni--;
        else if (s[t] == 'D') ni++;

        if (isValid(ni, nj) && !grid[ni][nj]) {
            grid[ni][nj] = 1;
            ans += countPaths(s, t + 1, ni, nj, grid);
            grid[ni][nj] = 0;
        }
    }

    return ans;
}

void solve() {
    string s;
    cin >> s;
    grid.assign(7, vector<int>(7, 0));
    grid[0][0] = 1;
    cout << countPaths(s, 0, 0, 0, grid);
}

int main(){
    fast_io;

    int t=1;
    // cin>>t; // uncomment if multiple test cases
    while(t--){
        solve();
    }

    return 0;
}