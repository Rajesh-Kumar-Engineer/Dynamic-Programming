#include<bits/stdc++.h>
using namespace std;
// Given an string and k we have to find longest k interspaces substring
int maxLength(string s , int k){
    // dp[i] = maximum length of k spaces substring
    int n = s.size();
    vector<int>dp(n,INT_MIN);
    int maxLength = INT_MIN;
    dp[0] = 1;
    // dp[i]= if we include ith idx or not 
    // if can be include dp[i] = 1+dp[i-1];
    //if not dp[i] = 1;
    for(int i =1 ; i <n ; i++){
        if(s[i] -s[i-1] <=k){
            // can be include;
            dp[i]= max(dp[i-1]+1, 1);
            maxLength = max(maxLength, dp[i]);
        }else{
            dp[i] = 1;
            maxLength = max(maxLength, dp[i]);
        }
    }
    return maxLength;

}