#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
STATE IDEA:
We want to work with numbers like:
1, 2, 3, ..., 9, 10, 11, 12, ...

And imagine writing them as a continuous string:
"12345678910111213..."

Query: find the k-th digit in this infinite sequence.

------------------------------------------------------------
HELPER 1: power(n)
------------------------------------------------------------
STATE:
Returns 10^n

TRANSITION:
- If n == 0 → 1
- If n == 1 → 10
- If n is odd:
    10 * (10^(n/2)) * (10^(n/2))
- If n is even:
    (10^(n/2)) * (10^(n/2))

NOTE:
This is recursive fast exponentiation, but NOT optimized
(because power(n/2) is called twice → exponential calls)
*/
long long power(int n)
{
    if(n==0)
        return 1;
    
    if(n==1)
        return 10;
    
    if(n%2)
    {
        // odd exponent: 10 * (10^(n/2))^2
        return 10 * power(n/2) * power(n/2);
    }
    
    // even exponent: (10^(n/2))^2
    return power(n/2) * power(n/2);
}


/*
------------------------------------------------------------
HELPER 2: digit(num, k)
------------------------------------------------------------
STATE:
Given a number `num`, return its k-th digit (1-indexed from LEFT)

Example:
num = 12345
k = 2 → return 2

TRANSITION:
1. Extract digits in reverse order
2. Traverse from most significant digit

EDGE:
If k > number of digits → return -1
*/
long long digit(long long num,long long k)
{   
    vector<long long> v;

    // extract digits (reversed)
    while(num > 0)
    {
        long long dig = num % 10;
        num = num / 10;
        v.push_back(dig);
    }

    // now traverse from most significant digit
    long long cnt = 1;
    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(cnt == k)
            return v[i];
        
        cnt++;
    }
    
    return -1; // invalid case
}


/*
------------------------------------------------------------
CORE FUNCTION: find(k, digitRange)
------------------------------------------------------------

STATE MEANING:

digitRange[i] =
Total digits used by all numbers with ≤ i digits

Example:
digitRange[1] → digits from [1..9]
digitRange[2] → digits from [1..99]
digitRange[3] → digits from [1..999]

------------------------------------------------------------
GOAL:
Find the k-th digit in the infinite sequence

------------------------------------------------------------
TRANSITION STEPS:

STEP 1: Identify BLOCK
--------------------------------
Find s such that:
digitRange[s] < k ≤ digitRange[s+1]

This means:
- The answer lies in numbers with (s+1) digits

--------------------------------
STEP 2: OFFSET INSIDE BLOCK
--------------------------------
num = k - digitRange[s]

This gives position INSIDE this block

--------------------------------
STEP 3: HANDLE EDGE CASES
--------------------------------
- If num == 0 → last digit of previous block
- If k == digitRange[e] → last number of block

--------------------------------
STEP 4: FIND EXACT NUMBER
--------------------------------
Each number has e digits

So:
index of number = num / e
remainder = num % e

--------------------------------
CASE 1: num % e == 0
→ exactly last digit of a number

CASE 2: otherwise
→ find digit inside next number

--------------------------------
FINAL STATE:
- compute actual number
- extract correct digit

*/
long long find(long long k,vector<long long> v)
{ 
    long long s = 0, e = 0;

    // STEP 1: find correct digit-length block
    long long i = 0;
    while(i + 1 <= 18)
    {
        if(v[i] <= k && v[i+1] >= k)
        {
            s = i;
            e = i + 1;
            break;
        }
        i++;
    }

    long long ans = 0;

    // STEP 2: relative position inside this block
    long long num = k - v[s];

    // EDGE CASE:
    // exactly at boundary → last digit of previous block
    if(num == 0)
    {
        return (power(s) - 1) % 10;
    }

    // EDGE CASE:
    // exactly end of current block
    if(v[e] == k)
    {
        return (power(e) - 1) % 10;
    }

    long long final_num = 0;

    // STEP 3: determine which number contains the digit
    if(num % e == 0)
    {
        // exact end of a number
        final_num = (power(s) - 1) + num / e;
        return final_num % 10;
    }
    else
    {
        // inside a number
        final_num = (power(s) - 1) + num / e + 1;

        // find specific digit
        ans = digit(final_num, num % e);
    }

    return ans;
}


/*
------------------------------------------------------------
MAIN DRIVER
------------------------------------------------------------

STATE:
digitRange[i] = total digits up to i-digit numbers

TRANSITION:
For i-digit numbers:
count = 10^i - 10^(i-1)
digits contributed = count * i

So:
digitRange[i] = digitRange[i-1] + count * i

------------------------------------------------------------
QUERY:
For each k:
→ find k-th digit
*/
int main() {
 
    vector<long long> digitRange(19, 0LL);

    // build prefix digit counts
    for(long long i = 1; i <= 18; i++)
    {
        digitRange[i] = digitRange[i-1] + (power(i) - power(i-1)) * i;
    }

    int q;
    cin >> q;

    while(q--)
    {
        long long k;
        cin >> k;
        
        long long digit_ans = find(k, digitRange);
        cout << digit_ans << endl;
    }
}
