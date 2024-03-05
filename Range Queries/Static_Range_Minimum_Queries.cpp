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
	vector<ll>arr;
	vector<ll>tree;

    SegmentTree(vector<ll>& nums) {
        int n = nums.size();
        arr = nums;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int index, ll value) {
        if (start == end) {
            arr[index] = value;
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= index && index <= mid) {
                update(2 * node, start, mid, index, value);
            } else {
                update(2 * node + 1, mid + 1, end, index, value);
            }
            tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 1e18;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_sum = query(2 * node, start, mid, l, r);
        ll right_sum = query(2 * node + 1, mid + 1, end, l, r);
        return min(left_sum , right_sum);
    }

};
void Ahemad(){
	ll n,q;
	cin>>n>>q;

	vl v(n);
	input(v);

	SegmentTree s(v);

	while(q--){
		int a,b;
		cin>>a>>b;

		a--;b--;
		cout<<s.query(1,0,n-1,a,b)<<endl;

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