#include<bits/stdc++.h>
using namespace std;

// given three array at each index you can only select one ele ad you can not select  continue one ele

int maxHappiness(vector<int>a,vector<int>b,vector<int>c){
    int n = a.size();
    vector<int>dp_a(n,0);
    vector<int>dp_b(n,0);
    vector<int>dp_c(n,0);
    dp_a[0] = a[0];
    dp_b[0] = b[0];
    dp_c[0] = c[0];
    for(int i =1 ; i < n ;i++){
        dp_a[i] = a[i] + max(dp_b[i-1], dp_c[i-1]);
        dp_b[i] = b[i] + max(dp_a[i-1], dp_c[i-1]);
        dp_c[i] = c[i] + max(dp_a[i-1], dp_b[i-1]);
    }
    return max({dp_a[n-1], dp_b[n-1], dp_c[n-1]});
}