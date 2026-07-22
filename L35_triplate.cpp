#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, 0));
    vector<vector<int>> dpc(n, vector<int> (n, 0));

    //lenght 1
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        dpc[i][i]=1;
    }

    //lenght 2
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            dpc[i][i+1]=3;
        }else{
            dpc[i][i+1]=2;
        }
    }

    //lenght 3
    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j = i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1;
            }
            dpc[i][j] = dpc[i+1][j] + dpc[i][j-1] - dpc[i+1][j-1] + dp[i][j];
        }
    }

    //making palindromic pairs
   
    vector<int> pdpp(n, 0);
    for(int i=0;i<n;i++){
        int j = i;
        int b = 0;
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }
            j--;
        }
        if(i+1<n){
            int rest = dpc[i+1][n-1];
            // cout<<dpc[i+1][n-1]<<endl;
            int val = b*rest;
            pdpp[i] = val;
        }
        
    }

    // int pairSum = 0;

    // for(int i=0;i<pdpp.size();i++){
    //     pairSum += pdpp[i];
    //     cout<<pdpp[i]<<" ";
    // }cout<<endl;
    // cout<<pairSum<<endl;

    //pdpp(palindromic dp pairs)

    //making palindromic dp triplets
    vector<int> pdpt(n, 0); //pdpt --> palindromic dp triplets
    for(int i=0;i<n;i++){
        int j = i;
        int b = 0;
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }
            j--;
        }
        if(i+1<n){
            int rest = 0;
            for(int k=i+1;k<n;k++){
                rest += pdpp[k];
            }
            int val = b*rest;
            pdpt[i] = val;
        }
        
    }

    int total = 0;
    for(int i=0;i<n;i++){
        // cout<<pdpt[i]<<" ";
        total += pdpt[i];
    }
    cout<<total<<endl;

   
}