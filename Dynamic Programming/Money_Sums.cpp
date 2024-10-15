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
#define print_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<arr[i][j]<<' ';}cout<<endl;}
#define input(a) for(auto &x:a) cin>>x;
#define printv(a) for(auto i:a) cout<<i<<' '; cout<<endl;
#define bpc(x) __builtin_popcountll(x)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vl,greater<ll>>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_setpp tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back


ll n;

bool solve(int i,int sum,int v[],vector<vi>&dp){

	if(sum==0) return 1;
	if(sum<0) return 0;
	if(i==n) return 0;

	if(dp[i][sum] != -1) return dp[i][sum];

	int ans=0;
	ans=(ans | solve(i+1,sum,v,dp));
	ans=(ans | solve(i+1,sum-v[i],v,dp));

	return dp[i][sum]=ans;
}


void Ahemad(){
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];

	vector<vi> dp(n+5,vi(100000+5,-1));
	list<int>li;
	for(int i=1;i<=100000 ;i++){
		if(solve(0,i,v,dp)){
			li.pb(i);
		}
	}

	cout<<li.size()<<endl;
	printv(li);
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