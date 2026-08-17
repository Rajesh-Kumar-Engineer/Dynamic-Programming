#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 


// given a two array such that you have to find maximum sum subset suchThat no two element is adjacent 

// a[] =  2 3 4 -8 2
// b[] = -5 8 3 1 -4

// dp[i] = best ans to the question if i is the size

int maxSumSubsetNoTwoAdjacentEle(vector<int>a , vector<int>b){
    int n = a.size();
    vector<int>dp(n+1,0);

    dp[0] = max(a[0] , b[0]);
    dp[1] =  max({dp[0] ,a[1] , b[1]});
    dp[2] =  max({a[2]+dp[0] , b[2] +dp[0] , dp[1]});
    //dp[i] = max(a[i]+dp[i-2], b[i]+dp[i-2], dp[i-1])
    for(int i = 2 ; i < n ; i++){
        dp[i] = max({a[i] + dp[i-2], b[i] + dp[i-2], dp[i-1]});
    }
    return dp[n-1];
}

//Please write main function for above question
int main(){
    vector<int> a = {2, 3, 4, -8, 2};
    vector<int> b = {-5, 8, 3, 1, -4};
    cout<<maxSumSubsetNoTwoAdjacentEle(a, b)<<endl;
    return 0;
}
