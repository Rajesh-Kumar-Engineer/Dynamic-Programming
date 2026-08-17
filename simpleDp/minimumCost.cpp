#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 

// minimum cost require to reach the destination from i we can reach i+1 or i+2;


int minCost(vector<int>cost){
    int n = cost.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = cost[0];
    dp[1] = abs(cost[1] - dp[0]);
    dp[2] = abs(cost[2] - cost[1]) + dp[1];

    // dp[i] = min(abs(cost[i]- cost[i-1]) + dp[i-1] , abs(cost[i] - cost[i - 3]) + dp[i-2]);
    for(int i = 3 ; i < n ; i++){
        dp[i] = min(abs(cost[i]- cost[i-1]) + dp[i-1] , abs(cost[i] - cost[i - 3]) + dp[i-2]);
    }
    return dp[n-1];
}