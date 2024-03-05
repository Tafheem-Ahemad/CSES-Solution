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

	SegmentTree(vector<ll>v) {
        int n=v.size();
        arr=v;
		seg.resize(4 * n + 2);
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
		seg[ind] = (seg[2 * ind + 1]+ seg[2 * ind + 2]);
	}

	ll query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0ll;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		ll left = query(2 * ind + 1, low, mid, l, r);
		ll right = query(2 * ind + 2, mid + 1, high, l, r);
		return (left+ right);
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = (seg[2 * ind + 1]+seg[2 * ind + 2]);
	}
};

void Ahemad(){
	ll n,q;
	cin>>n>>q;

	vl v(n);
	input(v);

	SegmentTree s(v);

	while(q--){
		int type;
		cin>>type;
		int a,b;
		cin>>a>>b;

		if(type==2){

			a--;b--;

			cout<<s.query(0,0,n-1,a,b)<<endl;

		}else{
			a--;
			s.update(0,0,n-1,a,b);
		}
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