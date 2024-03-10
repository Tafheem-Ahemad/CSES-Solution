#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int MOD=1e9+7;
  
int main(){
    int n;
    cin>>n;
 
    char grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
 
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
 
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i == n-1 && j== n-1){
                if(grid[i][j] == '.') dp[i][j]=1;
            } 
            else if(grid[i][j] == '*') dp[i][j]=0;
            else{
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
                dp[i][j]%=MOD;
            }
        }
    }
 
    cout<<dp[0][0]<<endl;
 
    return 0;
}
