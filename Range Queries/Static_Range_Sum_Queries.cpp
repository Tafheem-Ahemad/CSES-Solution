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

class Segment_Tree{
	public:

	vector<ll>arr;
	vector<ll>seg;

	Segment_Tree(vector<ll>v){
		int n=v.size();
		arr=v;
		seg.resize(4*n+2,0);
		build(0,0,n-1);
	}

	void build(int ind,int low,int high){
		if(low==high){
			seg[ind]=arr[low];
			return ;
		}

		int mid=(low+high)/2;
		build(2*ind+1,low,mid);
		build(2*ind+2,mid+1,high);

		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	ll query(int ind,int low,int high,int l,int r){
		// No Overlap
		if(l>high || r<low) return 0ll;

		// Complete overlap
		if(l<=low && high<=r) return seg[ind];

		// Partially overlap
		int mid=(low+high)/2;
		ll left=query(2*ind+1,low,mid,l,r);
		ll right=query(2*ind+2,mid+1,high,l,r);

		return (left+right);
	}

};
void Ahemad(){
	ll n,q;
	cin>>n>>q;

	vl v(n);
	input(v);

	Segment_Tree s(v);

	while(q--){
		int a,b;
		cin>>a>>b;

		a--;b--;

		cout<<s.query(0,0,n-1,a,b)<<endl;
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
