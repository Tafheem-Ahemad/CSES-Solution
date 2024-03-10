#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

int f(int i,int k,vector<vector<int>>& v,vector<vector<int>>& dp){
 
	int n=v.size();
	if(i >= n || k <= 0) return 0;
	if(dp[i][k] != -1) return dp[i][k];
 
	if( k < v[i][0]) return 0;
	int temp=max(f(i+1,k,v,dp),f(i+1,k-v[i][0],v,dp)+v[i][1]);
 
	return dp[i][k]=temp;
}
int main(){
 
	int n,k;
	cin>>n>>k;
	vector<vector<int>>v(n,vector<int>(2));
	vector<int>page(n);
	for(int i=0;i<n;i++){
		cin>>v[i][0];
	}
	for(int i=0;i<n;i++){
		cin>>v[i][1];
	}
 
	vector<vector<int>>dp(n+5,vector<int>(k+5,0));
 
	for(int i=n-1;i>=0;i--){
		for(int j=k;j>=0;j--){
			int temp=dp[i+1][j];
			if(j + v[i][0] <= k) temp=max(temp,dp[i+1][j+v[i][0]]+v[i][1]);
			dp[i][j]=temp;
		}
	}

	cout<<dp[0][0]<<endl;
 
	return 0;
