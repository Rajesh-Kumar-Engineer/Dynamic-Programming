#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    auto sum = [&](int l, int r) {
        return pref[r + 1] - pref[l];
    };

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len - 1 < n; i++) {

            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {

                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + sum(i, j));
            }
        }
    }

    cout << dp[0][n - 1];
}