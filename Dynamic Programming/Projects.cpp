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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_setpp tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back

ll dp[200005];

ll solve(int i,vl &start,vl &end, vl &reward){
	if(i>=start.size()) return 0;

	if(dp[i] != -1) return dp[i];

	ll mx=0;

	mx=max(mx,solve(i+1,start,end,reward)); // not_take

	// take part
	int it=upper_bound(all(start),end[i])-start.begin();
	mx=max(mx,reward[i]+solve(it,start,end,reward));

	return dp[i]=mx;
}
void Ahemad(){
	ll n;
	cin>>n;

	vector<vector<ll>>v(n,vector<ll>(3));
	for(int i=0;i<n;i++){
		cin>>v[i][0];
		cin>>v[i][1];
		cin>>v[i][2];
	}

	sort(all(v));

	vl start(n),end(n),reward(n);
	for(int i=0;i<n;i++) start[i]=v[i][0];
	for(int i=0;i<n;i++) end[i]=v[i][1];
	for(int i=0;i<n;i++) reward[i]=v[i][2];


	memset(dp,-1,sizeof(dp));
	ll ans=solve(0,start,end,reward);
	cout<<ans<<endl;
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