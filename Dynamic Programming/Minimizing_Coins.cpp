#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int f(vector<int>&nums,int x,vector<int>&dp){
 
	if(x==0) return 0;
	if(x<0) return INT_MAX;
	if(dp[x] != -1) return dp[x];
 
	int way=INT_MAX-1;
	for(int i=0;i<nums.size();i++){
		if(x<nums[i]) break;
		way=min(way,f(nums,x-nums[i],dp));
	}
 
	return dp[x]=way+1;
}
int main(){
 
	int n,x;
	cin>>n>>x;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
 
	sort(nums.begin(),nums.end());
	vector<int>dp(x+5,-1);
	int temp=f(nums,x,dp);
	if(temp == INT_MAX){
		cout<<-1<<endl;
	}else{
		cout<<temp<<endl;
	}

 
	return 0;
}
