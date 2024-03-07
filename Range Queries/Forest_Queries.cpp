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
#define take_matrix(a,n,m) for(int i=1; i<=n; i++){for(int j=1; j<=m; j++){cin>>a[i][j];}}
#define print_matrix(a,n,m) for(int i=0; i<=n; i++){for(int j=0; j<=m; j++){cout<<a[i][j]<<' ';}cout<<endl;}
#define input(a) for(auto &x:a) cin>>x;
#define printv(a) for(auto i:a) cout<<i<<' '; cout<<endl;
#define bpc(x) __builtin_popcountll(x)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vl,greater<ll>>
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
  
void Ahemad(){
	ll n,q;
	cin>>n>>q;
 
	vector<vector<char>>temp(n+1,vector<char>(n+1));
	vector<vector<int>>v(n+1,vector<int>(n+1,0));
	take_matrix(temp,n,n);
 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]=='*') v[i][j]=1;
			else v[i][j]=0;
		}
	}
 
 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[i][j]+=v[i][j-1];
			v[i][j]+=v[i-1][j];
			v[i][j]-=v[i-1][j-1];
		}
	}
 
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<v[c][d]-v[a-1][d]-v[c][b-1]+v[a-1][b-1]<<endl;
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
