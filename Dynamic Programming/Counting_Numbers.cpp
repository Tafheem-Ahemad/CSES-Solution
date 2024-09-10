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
#define vl vector<ll>
#define vi vector<int>
#define vs vector<string>
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

ll dp[20][12][2][2];

ll solve(int i,int prev,bool is_tight,bool is_started,string s){
	if(i==s.size()) return 1;
	if(dp[i][prev][is_tight][is_started] != -1) return dp[i][prev][is_tight][is_started];

	ll ans=0;
	if(is_tight==0){
		for(int ind=0;ind<=9;ind++){
			if(prev != ind || is_started==0) ans+=solve(i+1,ind,0,((ind>0) || is_started),s);
		}
	}else{
		ll upper=(s[i]-'0')-1;
		for(ll ind=0;ind<=upper;ind++){
			if(prev != ind || is_started==0) ans+=solve(i+1,ind,0,((ind>0) || is_started),s);
		}

		if(prev != (s[i]-'0') || is_started==0){
			ans+=solve(i+1,(s[i]-'0'),1,(((s[i]-'0')>0) || is_started),s);
		}
	}

	return dp[i][prev][is_tight][is_started]=ans;
}

void Ahemad(){
	/*Consistency doesn't guarantee that you will be successful
	But, not being consistent will guarantee that you won't reach success*/

	ll a,b;
	cin>>a>>b;

	memset(dp,-1,sizeof(dp));
	ll x;
	if(a==0) x=0;
	else x=solve(0,10,1,0,to_string(a-1));

	memset(dp,-1,sizeof(dp));
	ll y=solve(0,10,1,0,to_string(b));

	cout<<y-x<<endl;
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