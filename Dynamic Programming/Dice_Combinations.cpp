#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int MOD=1000000007;
int f(int n,vector<int>& dp){
 
	if(n<=0) return 1;
	if(dp[n] != -1) return dp[n];
 
	int ways=0;
	for(int i=1;i<=6 && n>=i;i++){
		ways+=f(n-i,dp);
		ways%=MOD;
	}
 
	return dp[n]=ways;
}
int main(){
 
	int n;
	cin>>n;
	vector<int>dp(n+2,-1);
	cout<<f(n,dp)<<endl;
 
	return 0;
}
