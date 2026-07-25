#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ;
int minimizeMaxSum(vector<int>& arr, int n, int k){
    // dp[i][k] = minimum possible sum of i element such that each part such that it divided 
    // into k partitions
    // dp[i][j] -> minimum sum of maximum elements for first i elements and j partitions
    // Base case: If we have 0 elements, the sum is 0 regardless of the number of partitions

    vector<vector<int>>dp(n+1,vector<int>(k+1, INT_MAX ));
    for(int i  = 0 ; i <=k ; i++){
        dp[0][i] = 0;
    }

    // dp[i][k] -> best way to divide array of size i into k parts
    for(int i = 1 ; i <=n ; i++){
        for(int parts =1 ; parts <= k ; parts++){
            int curMax=0;
            // Fix the last j elements for the current partition
            for(int j = i ; j >=1 ; j--){
                curMax = max(curMax, arr[j-1]);
                if(dp[j-1][parts-1] !=INT_MAX){
                    dp[i][parts] = min(dp[i][parts], curMax + dp[j - 1][parts - 1]);
                }


            }
        }
    }
    return dp[n][k];
    
}

// Given an array we have to divide the array in k parts such that sum of maximum of each part is minimize

int main() {
    int n, k;
    cin >> n;
    cin >> k;
 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int result = minimizeMaxSum(arr, n, k);
    cout << "Minimum sum of maximum elements of each partition: " << result << endl;
 
    return 0;
}