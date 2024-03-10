#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define F first
#define S second
const int MOD=1e9+7;
#define vl	vector<ll>
#define vi	vector<int>
#define vs	vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ump unordered_map
#define all(v) v.begin(),v.end()
#define take_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cin>>a[i][j];}}
#define print_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<a[i][j]<<' ';}cout<<endl;}
#define input(a) for(auto &x:a) cin>>x;
#define printv(a) for(auto i:a) cout<<i<<' '; cout<<endl;
#define bpc(x) __builtin_popcountll(x)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vl,greater<ll>>
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll f(int i,int last,vector<int>& v,int m,vector<vector<ll>>& dp){
 
	int n=v.size();
	if( i >= n){
		return 1;
	} 
	if(i > 0 && v[i] != 0 && abs(v[i]-last) > 1) return 0; // cheack
	if(dp[i][last] != -1) return dp[i][last];
 
	ll count=0;
	if(i == 0 && v[i] == 0){
		for(int idx=1;idx<=m;idx++){
			count+=f(i+1,idx,v,m,dp);
		}
	}else if(v[i] == 0){
		for(int idx=max(1,last-1);idx<=min(m,last+1);idx++){
			count+=f(i+1,idx,v,m,dp);
		}
	}else{
		count+=f(i+1,v[i],v,m,dp);
	}
 
	return dp[i][last]=count%MOD;
}
void Ahemad(){
 
	int n,m;
	cin>>n>>m;
	vi v(n);
	input(v);
 
	vector<vector<ll>>dp(n+5,vector<ll>(m+5,-1));
	cout<<f(0,0,v,m,dp)<<endl;
 
}
 
 
int main(){
	fast();
	ll t=1;
	// cin>>t;
	for(ll o=1;o<=t;o++){
		Ahemad();
		//cout<<"case : "<<o<<endl;
	}
	return 0;
}
