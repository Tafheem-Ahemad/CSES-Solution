#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int f(int n,vector<int>& dp){
 
	if(n==0) return 0;
	if(n<0) return INT_MAX;
 
	if(dp[n] != -1) return dp[n];
 
	int num=n;
	int mn=INT_MAX;
	while(num){
		int z=num%10;
		if(z) mn=min(mn,f(n-z,dp));
		num/=10;
	}
 
	return dp[n]=mn+1;
}
int main(){
 
	int n;
	cin>>n;
	vector<int>dp(n+5,-1);
	cout<<f(n,dp)<<endl;
 
	return 0;
}
