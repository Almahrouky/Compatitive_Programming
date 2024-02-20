#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
struct BIT {
	int tree[N];

	void init() {
		memset(tree, 0, sizeof(tree));
	}

	void add(int pos, int val) {
		for (++pos; pos <= N; pos += (pos & (-pos))) {
			tree[pos - 1] += val;
		}
	}

	int get(int pos) {
		int ret = 0;
		for (++pos; pos; pos -= (pos & (-pos))) {
			ret += tree[pos - 1];
		}
		return ret;
	}

	int find(int target) {
		int st = 0;
		for (int sz = N >> 1; sz; sz >>= 1) {
			if (tree[st + sz - 1] < target) {
				target -= tree[(st += sz) - 1];
			}
		}
		return st;
	}
};

struct MultiSet {
	BIT bit;
	MultiSet() {
		bit.init();
		bit.add(0, -1);
	}

	void insert(int val) { bit.add(val, 1); }

	void erase(int val) { bit.add(val, -1); }

	int count(int val) { return bit.get(val) - bit.get(val - 1); }

	int size() { return bit.get(N - 1) + 1; }

	int at(int idx) { return bit.find(idx); }
};
#define fr(n) for(int i = 0; i < n; ++i)
#define frj(m) for(int j = 0; j < m; ++j)
#define all(v) v.begin(), v.end()
int dx[] = {0, -1, 0, 1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
char di[] = {'R', 'U', 'L', 'D'};
void Almahrouky() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
const int mod = 1e9 + 7;
const int inf = 1e18;
const int N = 2e5 + 5;
const int N = 1 << 18, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

void sol() {

}
int32_t main() {
	Almahrouky();
	int t; cin >> t;
	while (t--) {
		sol();
		cout << '\n';
	}

	return 0;
}