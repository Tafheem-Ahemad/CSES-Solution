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

const int N=1000005;
ll solve(int n,int shape,vector<vector<ll>>&dp){

	if(n==1){
		return 1;
	}
	if(dp[n][shape] != -1) return dp[n][shape];

	ll count=0;
	if(shape==1){
		count+=(4*solve(n-1,1,dp))%MOD;
		count%=MOD;

		count+=solve(n-1,0,dp)%MOD;
		count%=MOD;
	}else{
		count+=solve(n-1,1,dp)%MOD;
		count%=MOD;
		count+=solve(n-1,0,dp)%MOD;
		count%=MOD;
		count+=solve(n-1,0,dp)%MOD;
		count%=MOD;
	}

	return dp[n][shape]=count;
}

// map<ll,ll>mp;
// void Ahemad(){
// 	int x;
// 	cin>>x;

// 	if(mp.count(x)){
// 		cout<<mp[x]<<endl;
// 		return ;
// 	}

// 	ll a=1,b=1;
// 	for(ll i=2;i<=x;i++){
// 		ll new_a=0;
// 		new_a+=a%MOD;
// 		new_a%=MOD;
// 		new_a+=a%MOD;
// 		new_a%=MOD;
// 		new_a+=b%MOD;
// 		new_a%=MOD;

// 		ll new_b=0;
// 		new_b+=(4*b)%MOD;
// 		new_b%=MOD;
// 		new_b+=a%MOD;
// 		new_b%=MOD;

// 		a=new_a;
// 		b=new_b;
// 	}

// 	ll ans=(a+b)%MOD;
// 	mp[x]=ans;
// 	cout<<ans<<endl;
// }


ll dp[1000005][2];
void Ahemad(){
	for(int i=1;i<=1000002;i++){
		if(i==1){
			dp[i][0]=1;
			dp[i][1]=1;
		}else{
			dp[i][0]+=dp[i-1][0]%MOD;
			dp[i][0]%=MOD;
			dp[i][0]+=dp[i-1][0]%MOD;
			dp[i][0]%=MOD;
			dp[i][0]+=dp[i-1][1]%MOD;
			dp[i][0]%=MOD;

			dp[i][1]+=(4*dp[i-1][1])%MOD;
			dp[i][1]%=MOD;
			dp[i][1]+=dp[i-1][0]%MOD;
			dp[i][1]%=MOD;
		}
	}

}

int main(){
	fast();
	ll t=1;
	cin>>t;
	// mp.clear();
		Ahemad();
	for(ll o=1;o<=t;o++){
		// cout<<"case : "<<o<<endl;
		int x;
		cin>>x;
		cout<<(dp[x][0]+dp[x][1])%MOD<<endl;
	}
	return 0;
}