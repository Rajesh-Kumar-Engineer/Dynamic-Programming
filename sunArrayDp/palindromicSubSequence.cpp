#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubSequence(string s){
    int n = s.size();
    vector<vector<int>>dpCount(n , vector<int>(n,0)); // dpCount[i][j] = no of SubSequence which are palindrome [i....j]
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i = 0 ; i <n ; i++){
        dp[i][i] = true;
        dpCount[i][i] = 1;
    }
    // for length 2
    for(int i =0 ; i <n-1 ; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            dpCount[i][i+1] = 3;
        }else{
            dpCount[i][i+1] = 2;
        }
    }

    //for len 3 , 4 ,...,n
    for(int len = 3 ; len <=n ; len++ ){
        for(int i = 0 ; i <n-len+1 ; i++){
            int j = i+len-1;
            if(s[i] == s[j]){
                dp[i][j] = 1;
                dpCount[i][j] = dpCount[i+1][j] + dpCount[i][j-1] +1;

            }else{
                dpCount[i][j] = dpCount[i+1][j] + dpCount[i][j-1] - dpCount[i+1][j-1];
            }
        }
    }
    return dpCount[0][n-1];
}

int main() {
    string s = "geeksforgeeks"; 
    cout << countPalindromicSubSequence(s); 
}