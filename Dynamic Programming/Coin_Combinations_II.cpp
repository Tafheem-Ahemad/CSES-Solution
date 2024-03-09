#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int countWaysToMakeChange(int coin[], int n, int value)
{
	int MOD=1000000007;
    vector<long long>dp(value+10,0);
    dp[0]=1;
    for(int i=0;i<n;i++){//go to the each coin
 
        for(int j=1;j<=value;j++){
            if(j-coin[i] < 0) continue;
            dp[j]=(dp[j]%MOD+(dp[j-coin[i]])%MOD)%MOD;
        }
    }
 
    return dp[value];
}
 
int main(){
 
	int n,val;
	cin>>n>>val;
	int v[n];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
 
	cout<<countWaysToMakeChange(v,n,val)<<endl;
 
	return 0;
}
