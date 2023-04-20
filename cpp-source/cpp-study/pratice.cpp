#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
#define xx first
#define yy second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pii dir[] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
int N, seg[500005 * 4];
pii arr[500005];
ll cnt;

void update(int n) {
	while (n != 0) {
		seg[n]++;
		n /= 2;
	}
}
ll get(int s, int e) {
	ll ans = 0;
	while (s <= e) {
		if (s % 2 == 1) ans += seg[s++];
		if (e % 2 == 0) ans += seg[e--];
		s /= 2, e /= 2;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int s = 1;
	while (s < N) s *= 2;
	s--;
	for (int i = 1,a; i <= N; i++) {
		cin >> a;
		arr[i] = { -a,-i };
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		cnt += get(s + 1, s - arr[i].yy);
		update(s - arr[i].yy);
	}
	cout << cnt;
}
