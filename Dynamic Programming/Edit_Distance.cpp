/*
	Name :- Tafheem Ahemad
*/
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
#define vll vector<vl>
#define vii vector<vi>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ump unordered_map
#define all(v) v.begin(),v.end()
#define take_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cin>>a[i][j];}}
#define print_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<a[i][j]<<' ';}cout<<endl;}
#define input(a) for(auto &x:a) cin>>x;
#define printv(a) for(auto &i:a) cout<<i<<' '; cout<<endl;
#define yes(x) if(x) cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define cl(n) for(int i=0;i<=n+5;i++) g[i].clear()
#define mem(v,z) memset(v,z,sizeof(v))
#define bpc(x) __builtin_popcountll(x)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vl,greater<ll>>
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define in insert
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<vector<ll>>delta1={{1,0},{-1,0},{0,-1},{0,1}};
vector<vector<ll>>delta2={{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};

ll dp[5005][5005];
string s1,s2;

ll solve(int i,int j){
 
    ll m=s1.size(),n=s2.size();
    if(i == m) return n-j;
    if(j == n) return m-i;
    if(dp[i][j] != -1) return dp[i][j];
 
    ll temp=1e18;
    if(s1[i] == s2[j]){
        temp=min(temp,solve(i+1,j+1));
    }else{
        temp=min(temp,solve(i,j+1)+1);// insert
        temp=min(temp,solve(i+1,j)+1);//delete
        temp=min(temp,solve(i+1,j+1)+1);//both make equal
    }
 
    return dp[i][j]=temp;
}

void Ahemad(){
	/*Consistency doesn't guarantee that you will be successful
	But, not being consistent will guarantee that you won't reach success*/


	cin>>s1>>s2;

	mem(dp,-1);
    cout<<solve(0,0)<<endl;

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