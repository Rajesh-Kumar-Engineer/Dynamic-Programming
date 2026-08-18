
// Link to the problem :-> https://www.desiqna.in/15099/shaw-super-hard-dynamic-programming-solution-kumar-2023-may 





// 1<=n<=100
// 1<=cost[i]<=100
// 1<=happy[i]<=100
// 1<=max,min<=100
// 1<=m<=100 


// Understanding :- You are given an array of size N name cost[i] ; you are also given happy[i] ; max[i] ; min[i] ; m-> total budget 

// Do shopping in such a way such that you get maximum happiness in the given money 

// Observation:-> dp[i] = best answer to question if you consider the first “i” items! -> max happiness for the first “i” items!


// -> one more parameter which we are missing ; is money ; you need to know the best happiness for the first “i” such that you can spend maximum j money 

// -> dp[i][j] = maximum happiness you can get if you consider first “i” items and you have exact “j” cost(money)


// COST = [ 5 5 ] 

// HAPPY = [ 100 1] 

// MIN = [1 1]

// MAX = [6 6]

// -> 30 

// DP[1][0] = it was compulsory to buy at least 1 time; you cant even do that so answer is INT_MIN. 

// DP[1][1] = INT_MIN
// DP[1][2] = DP[1][3] = DP[1][4] = INT_MIN. 

// DP[1][5] = 100 
// DP[1][6] = 100 
// DP[1][7] = 100
// DP[1][8] = 100
// DP[1][9] = 100 

// DP[1][10] = 200 

// .
// .
// .
// .
// .
// DP[1][15] = 300
// .
// .
// DP[1][20] = 400

// DP[1][25] = 500

// DP[1][30] =600


// DP[2][10] = you are now forced to buy atleast 1 item of type 2
// = 1 + now much money you have left -> 5 ; so now you can buy the remaining item of type in maximum 5 rupees which is nothing but dp[1][5] = 1*100 + dp[1][5]  
// dp[i][j]=happy[i]+dp[i-1][j-p[i]]


// dp[i][j] = (buy at least min[i] item of type “i” + dp[i-1][leftover_money])

// OR 

// (buy at least min[i] + 1 item of type “i” + dp[i-1][leftover_money])

// OR 

// (at least min[i] + 2 item of type "i" + dp[i-1][leftover_money])

// OR
// .
// .
// .
// .
// .
// OR
// max[i] of type i +dp[left_money]


// -> final val will be max of all these choices! 

// final answer will be dp[n][m]
// Pseudo Code. https://ideone.com/AjYjuQ 
// -> In DP Problem; making correct base case is hardest job to do in least time left for contest 



// TC : O(N^3)

// SC : O(N^2) 

// DP[0][0] = 0 
// DP[0][5] = 0 


#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 
ll dp[105][105] ; 
 
int main() {

    ll n;
    cin >> n;

    ll cost[n + 1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    cin >> n;
    ll happy[n + 1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> happy[i];
    }

    cin >> n;
    ll mn[n + 1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> mn[i];
    }

    cin >> n;
    ll my[n + 1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> my[i];
    }

    ll m;
    cin >> m;

    for (ll i = 0; i < 105; i++) {
        for (ll j = 0; j < 105; j++) {
            dp[i][j] = -1e18;
        }
    }

    // If dp[0][0] should be the starting state
    dp[0][0] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {

            ll final_answer = -1e18;

            for (ll count = mn[i]; count <= my[i]; count++) {

                ll g = count * cost[i];

                if (j - g >= 0) {
                    ll answer = dp[i - 1][j - g] + count * happy[i];
                    final_answer = max(final_answer, answer);
                }
            }

            dp[i][j] = final_answer;

            cout << i << " " << j << " " << dp[i][j] << '\n';
        }
    }

    if (dp[n][m] < 0)
        cout << "0";
    else
        cout << dp[n][m];

    return 0;
}