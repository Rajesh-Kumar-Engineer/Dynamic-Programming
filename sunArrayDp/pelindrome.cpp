#include<bits/stdc++.h>
using namespace std;

//find the number of palindromic  substring
// dp[i.....j]  == true ---> s[i...j] is palindrome


int countPalindrome(string s){
    // 1 one length 
    int n = s.length();
    vector<vector<bool>>dp(n,vector<bool>(n,true));
    int count = 0 ;
    int start = 0;
    int maxLength = 1;
    // length 1
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = true;
        count++;
    }
    // len 2
    for(int i = 0 ; i <n-1 ; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = true;
            count++;
            if(maxLength < 2){
                start = i ;
                maxLength = 2;
            }
        }
    }
    //len 3 , 4, .... n

    for(int len = 3 ; len <=n ; len++){
        for(int i = 0 ; i <n-len+1 ; i++){
            int j = i+len -1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                count++;
                if(maxLength < len){
                    start = i ;
                    maxLength = len;
                }
            }
        }
    }
    // maxLength -> maximum length of palindromic substring
    return count;

}