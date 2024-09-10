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

ll solve(int i,int sum,int n,vector<vector<ll>>&dp){
	// cout<<i<<endl;
	if(sum<0 || i>n) return 0;
	if(sum==0 ) return 1;

	if(dp[i][sum] != -1) return dp[i][sum];

	ll count=0;
	count+=solve(i+1,sum,n,dp)%MOD; // not take
	count%=MOD;
	count+=solve(i+1,sum-i,n,dp)%MOD; // take
	count%=MOD;

	return dp[i][sum]=count;
}
void Ahemad(){
	int n;
	cin>>n;

	int sum=(n*(n+1))/2;
	if(sum%2){
		cout<<0<<endl;
	}else{
		vector<vector<ll>>dp(n+5,vector<ll>((sum/2)+5,-1));
		ll ans=solve(1,sum/2,n,dp);
		cout<<ans<<endl;
	}
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