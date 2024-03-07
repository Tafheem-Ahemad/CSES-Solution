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
 
class SegmentTree {
public:
	vector<ll> arr;
	vector<ll> seg;
	int n;
 
	SegmentTree(vector<ll> v) {
        n=v.size();
        arr=v;
		seg.resize(4 * n + 5);
        build(0,0,n-1);
	}
 
	void build(int ind, int low, int high) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid);
		build(2 * ind + 2, mid + 1, high);
		seg[ind] = max(seg[2 * ind + 1],seg[2 * ind + 2]);
	}
 
	ll query(int ind, int low, int high, int val) {
		if(seg[ind]<val) return -1;
 
		if(low==high){
			seg[ind]-=val;
			return low;
		}
 
		int mid=(low+high) >> 1;
		if(seg[2*ind+1]>=val){
 
			ll ans=query(2*ind+1,low,mid,val);
			seg[ind] = max(seg[2 * ind + 1],seg[2 * ind + 2]);
			return ans;
		}else{
			ll ans=query(2*ind+2,mid+1,high,val);
			seg[ind] = max(seg[2 * ind + 1],seg[2 * ind + 2]);
			return ans;
		}
	}
 
};
 
void Ahemad(){
	ll n,q;
	cin>>n>>q;
 
	vector<ll>v(n);
	input(v);
 
	SegmentTree s(v);
 
	while(q--){
		int x;
		cin>>x;
		
		cout<<s.query(0,0,n-1,x)+1<<" ";
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
