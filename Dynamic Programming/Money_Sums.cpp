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

unordered_set<ll> dp[105];

unordered_set<ll> solve(int ind,vl &v){

	int n=v.size();
	if(ind==n-1) {
		unordered_set<ll>st;
		st.insert(0ll);
		st.insert(v[n-1]);
		return st;
	}

	unordered_set<ll>st = solve(ind+1,v);
	unordered_set<ll>ans;

	for(auto i:st){
		ans.insert(i);
		ans.insert(i+v[ind]);
	}

	return dp[ind]=ans;
}


void Ahemad(){
	ll n;
	cin>>n;

	vl v(n);
	input(v);

	unordered_set<ll> ans=solve(0,v);
	ans.erase(0ll);
	vl t(ans.begin(),ans.end());
	sort(all(t));

	cout<<ans.size()<<endl;
	printv(t)
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