#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// ll dp[50000][50000][50000];

int main() {
	// your code goes here
	ll n;
	cin>>n;
	
	ll c1;
	cin>>c1;
	
	ll c2;
	cin>>c2;
	
	ll w[n+1] = {0};
	ll p[n+1] = {0};
	
	ll i = 1;
	while(i<=n){
		cin>>p[i];	
		i++;
	}
	
	i = 1;
	while(i<=n){
		cin>>w[i];
		i++;
	}
	
	ll dp[n+5][c1+5][c2+5] = {0};
// 	dp[i][j][k] means we have considered first ith item and
//  first bag have remaining capacity is j
//  and second bag have remaining capacity is k.

    // Base case :- 
    i = 1;
	while(i<=n){
		ll j = 1;
		while(j<=c1){
		    ll k = 1;
		    while(k<=c2){
                if(i ==0 or j == 0 or k == 0){
                    dp[i][j][k] = 0;
                }
		        k++;
		    }
			j++;
		}
		i++;
	}
	
    ll v1=0,v2=0,v3=0;
	i = 1;
	while(i<=n){
		ll j = 1;
		while(j<=c1){
		    ll k = 1;
		    while(k<=c2){
                v1=dp[i-1][j][k];
				if(j-w[i]>0){
					v2=p[i]+dp[i-1][j-w[i]][k];
				}
				if(k-w[i]>0){
					v3=p[i]+dp[i-1][j][k-w[i]];
				}
				dp[i][j][k]=max(v1,max(v2,v3));
		        k++;
		    }
			j++;
		}
		i++;
	}

	cout<<dp[n][c1][c2];
	return 0;
}