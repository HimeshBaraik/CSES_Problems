#include <bits/stdc++.h>
using namespace std;

/*
    Function: order
    उद्देश्य:
    Given frequency of characters (A-Z), construct a string such that
    no two adjacent characters are the same.

    Approach:
    Greedy strategy:
    - Always try to place the character with maximum remaining frequency.
    - BUT if it violates adjacency condition, pick the next valid character.
    - Also handle the case when a character frequency is too high to fit.
*/
string order(vector<int> &fre, int n) {
    
    string ans;

    // Loop n times to construct result string
    for(int i = 0; i < n; i++) {

        int maxi = 0;     // stores max frequency
        int index = 0;    // index of char with max frequency

        // Find character with maximum frequency
        for(int j = 0; j < 26; j++) {
            if(fre[j] > maxi) {
                maxi = fre[j];
                index = j;
            }
        }

        // Remaining positions
        int remaining = n - ans.length();

        /*
            Important condition:
            If max frequency > remaining/2,
            then we MUST place this character now,
            otherwise it will be impossible later.
        */
        if(maxi > remaining / 2) {

            // Check adjacency condition
            if(ans.length() == 0 || (char('A' + index) != ans.back())) {
                ans.push_back(char('A' + index));
                fre[index]--;
            }
        }
        else {
            /*
                Otherwise, pick ANY valid character
                which is not same as last character
            */
            for(int j = 0; j < 26; j++) {
                if(fre[j] > 0 &&
                   (ans.length() == 0 || char('A' + j) != ans.back())) {
                    
                    ans.push_back(char('A' + j));
                    fre[j]--;
                    break;
                }
            }
        }
    }

    return ans;
}

int main() {

    string s;
    cin >> s;

    // Frequency array for A-Z
    vector<int> fre(26, 0);

    // Count frequency of each character
    for(int i = 0; i < s.length(); i++) {
        fre[s[i] - 'A']++;
    }

    // Generate answer string
    string ans = order(fre, s.length());

    /*
        If constructed string length == original length
        → valid rearrangement
        else → impossible
    */
    if(ans.length() == s.length())
        cout << ans << endl;
    else
        cout << -1 << endl;
}
