#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int longestPalindromicSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
 
    // Base case: Single character palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
 
    // Build the DP table
    for (int len = 2; len <= n; len++) {  // length of the substring
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = max({2 + dp[i + 1][j - 1], dp[i][j - 1], dp[i + 1][j]});
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
 
    return dp[0][n - 1];  // Answer for the full string
}
 
int main() {
    string s;
    cin >> s;
    cout << longestPalindromicSubsequence(s) << endl;
    return 0;
}