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

ll dp[505][505];

ll solve(int n,int m){
	if(n==m){
		return 0;
	}

	if(dp[n][m] != -1) return dp[n][m];
	if(dp[m][n] != -1) return dp[m][n];

	ll mn=1e9;

	//Vertical cut
	for(int i=1;i<m;i++){
		mn=min(mn,1ll+solve(n,i)+solve(n,m-i));
	}

	//Horizontal cut
	for(int i=1;i<n;i++){
		mn=min(mn,1ll+solve(i,m)+solve(n-i,m));
	}

	return dp[n][m]=dp[m][n]=mn;
}

void Ahemad(){
	ll n,m;
	cin>>n>>m;

	memset(dp,-1,sizeof(dp));
	ll ans=solve(n,m);
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