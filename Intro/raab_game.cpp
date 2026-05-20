#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        // number of draws required
        int draw = n - a - b;

        // If draws become negative → impossible
        if (draw < 0) {
            cout << "NO" << endl;
            continue;
        }

        // Create base vector [1 ... n-draw]
        vector<int> v;
        for (int i = 1; i <= (n - draw); i++) {
            v.push_back(i);
        }

        vector<pair<int, int>> ans; // store pairs (p1, p2)

        int k = 1;
        int m = v.size();

        // Create 'a' pairs where first > second
        // (i.e., wins for first player)
        while (k <= a) {
            ans.push_back({v[m - 1 - a + k], k});
            k++;
        }

        k = 1;

        // Create 'b' pairs where first < second
        // (i.e., wins for second player)
        while (k <= b) {
            ans.push_back({k, v[m - 1 - b + k]});
            k++;
        }

        k = 1;

        // Create 'draw' pairs (same values)
        while (k <= draw) {
            ans.push_back({n + 1 - k, n + 1 - k});
            k++;
        }

        // Counters to verify correctness
        int cnt1 = 0; // count of first > second
        int cnt2 = 0; // count of first < second

        vector<int> v1, v2; // final permutations

        // Process all pairs
        for (auto &p : ans) {
            if (p.first > p.second) {
                cnt1++;
            } else if (p.first < p.second) {
                cnt2++;
            }

            v1.push_back(p.first);
            v2.push_back(p.second);
        }

        // Validate if we got correct counts
        if (cnt1 != a || cnt2 != b) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            // Print first permutation
            for (int x : v1) {
                cout << x << " ";
            }
            cout << endl;

            // Print second permutation
            for (int x : v2) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
