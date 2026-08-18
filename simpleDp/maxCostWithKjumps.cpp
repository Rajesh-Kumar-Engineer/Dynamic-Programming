// You can take jump from i = 1, 2 , 3 , 4 ,...,k
#include <bits/stdc++.h>
using namespace std;

int minScore(vector<int> cost, int k) {
    int n = cost.size();

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {

            dp[i] = min(
                dp[i],
                dp[i - j] + abs(cost[i] - cost[i - j])
            );
        }
    }

    return dp[n - 1];
}