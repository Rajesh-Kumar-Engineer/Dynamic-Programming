#include <bits/stdc++.h>
 
using namespace std;

string g;
typedef int ll ; 
int cl(int x,int y){
    //cout<<x<<" "<<y<<"\n";
    
    int i = y ; ll c = 0 ;ll b = 0 ; 
    while(i>=x){
        if(g[i]=='1'){
            c = c + pow(2,b);
        }
        i--;b++;
    }
    return c ; 
}


class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        g = s;
        int dp[100]={100};
        dp[0] = 0 ; 
        int G = s.size();
        int i = 0 ; 
        while(i<G){
            
            ll answer = 100;
            
            ll j = i ; 
            while(j>=0){
                ll g = cl(j,i); 
                
                
                
                if(s[j]!='0' && g!=0 && (15625%g)==0){
                    answer = min(answer,dp[j] + 1);
                   
                
                    
                    
                }
                j--;
            }
          
            
            dp[i+1] = answer ; 
            
            i++;
        }
        
        if(dp[G]==100){
            dp[G] = -1;
        }
        
        return dp[G] ; 
    }
};


// followup question

// Understanding :-> Given an array of Size “N”; divide it into some parts; such that each part is of size>=K and the max - min of that part should be <=M 


// --->n
 
// --->b[n+1] 
 
// --->dp[n+1] = {LARGE VALUE} 
 
// --->dp[0] = 0 
 
// ---> i = 1 
 

// https://ideone.com/wAIped  link