// Given an array of size "N" you have to find the number of ways to partition such that sum of each part is <=M


// dp[i] number of ways to partition till ith idx such that the sum of each part is <=m

#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ; 
ll dp[105];
int main(){
    ll n ; 
    cin>>n ; ll m ; 
    cin>>m ; 
    ll b[n+1] = {0};
 
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }

    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 2 ; i <=n ; i++){
        ll v ;
        ll j =i;
        ll sum = b[i];
        while(j>=1 && sum <=m){
            ll g = dp[j-1];
            v = v + g ; 
            j--;
            sum = sum + b[j];
        }
        dp[i] = v;
    }

    cout<<dp[n];


    // -> Given an array of size ‘N’; find the number of ways to partition it such that the sum of each part is <=M ; but you should only make k partitions!

    ll dp[105][105];
    for(ll i=0;i<=100;i++){
        for(ll j=0;j<=100;j++){
            dp[i][j] = -1e18;
        }
    }
    
    dp[0][0] = 1 ; 
    dp[1][1] = 1 ; 

    ll k =5;
    for(ll i=2;i<=n;i++){
 
        ll prt = 1 ; 
        while(prt<=k){
            ll v = 0 ; 
            ll j = i ; ll sum = b[i]; 
            while(j>=1 && sum<=m){
    
                ll g = dp[j-1][prt-1];
                //cout<<j-1<<" "<<prt-1<<" "<<dp[j-1][prt-1]<<"\n";
    
                if(g>0){
                v = v + g ; 
                }
                j--;
                sum = sum + b[j] ; 
            }
 
            if(v>0){
    
            dp[i][prt] = v ; 
            }
    
            cout<<i<<" "<<prt<<" "<<dp[i][prt]<<"\n";
    
    
            prt++;
        }
    }
    return 0;
}

