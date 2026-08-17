#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ;
// given an array find the maximum sumsubset where no adjacent element in the subset


int maxSumSubset(vector<int>arr){

    // dp[i] =  maximum sum subset if the size of the array is "i" or best answer to the question is size is "i"
    int n = arr.size();
    vector<int>dp(n+1,0);
    dp[0] = arr[0];
    dp[1] = max(dp[0] ,arr[1]);
    // dp[i] = max(arr[i] + dp[i-2] , dp[i-1])

    for(int i = 2 ; i < n ;i++){
        dp[i] = max(arr[i] + dp[i-2] , dp[i-1]);
    }
    return dp[n-1];
}

// write main function
int main(){

    vector<int>arr = {2, 1, 4, 9};
    cout<<maxSumSubset(arr)<<endl;
    return 0;
}