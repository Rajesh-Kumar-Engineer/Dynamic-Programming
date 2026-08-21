// dp[i][j] = tells you the best answer in the range [i....j]

// first we calculate for len 1 --> dp[1][1],dp[2][2],.....dp[n][n]
// then we calculate for len 2--> dp[1][2],dp[2][3].....,dp[n-1][n]
// then we calculate for len 3
// then we calculate for len 4
// and so on...   n

//  for the subarray please tell me it is Palindrome or not
//dp[i][i] = true; 
//for len 2 = dp[i][i+1]==true if(s[i]==s[i+1])
// dp[i][j] = true if(s[i]==s[j] && dp[i+1][j-1]==true])


// Q2 follow up for the given query q Please tell me hoq many palindromes in it
#include<bits/stdc++.h>
using namespace std;
vector<int> countPalindrome(string s , vector< vector<int> > q){
    int n = s.length();
    vector< vector<int> >dp(n,vector<int>(n,0));
    vector< vector<int> >dpCount(n,vector<int>(n,0));

    for(int i = 0 ; i < n ; i++){
        dp[i][i] = 1;
        dpCount[i][i] = 1;
    
    }
    // for length 2
    for(int i = 0 ; i <n-1 ; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            dpCount[i][i+1] = 3;
        }else{
            dpCount[i][i+1] = 2;
        }
    }

    // for len 3 ,4,5...n
    for(int len = 3 ; len <=n ; len++){
        for(int i = 0 ; i <n-len+1; i++){
            int j = i + len -1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1; 
            }
            dpCount[i][j] = dpCount[i][j-1] + dpCount[i+1][j] - dpCount[i+1][j-1] + dp[i][j]; 

        }
    }

    vector<int>ans;
   for(int i =0 ; i < n ; i++){
        int s = q[i][0], e = q[i][1];
        ans.push_back(dpCount[s][e]);
   }
   return ans;

   // folow up
   // valid pairs

   vector<int>validPair(n,0);
   for(int i = 0 ; i < n ; i++){
        int j = i ;
        int b = 0 ; 
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }
            j--;
        }
        if(i+1 < n ){
            int rest = dpCount[i+1][n-1];
            int val = b*rest;
            validPair.push_back(val);
        }
   }
   // valid tuple
   vector<int>validTuple(n, 0);
   for(int i =0 ; i < n ; i++){
        int j = i;
        int t =0 ;
        while(j>=0){
            if(dp[j][i]==1){
                t++;
            }
        }
        if(i+1 < n ){
            // find valid pairs
            int rest = 0;
            for(int k = i+1 ; k < n ; i++){
                rest+=validPair[k];
            }
            int val = rest*t;
            validTuple.push_back(val);
        }
   }
   return validTuple;
}
