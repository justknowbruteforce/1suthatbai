#include <iostream>
#include <map>
using namespace std;
#define maxn int(1e6+7)
#define ull unsigned long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull res1 = 0, res2 = 0;
	map<ull, ull> mp;
	int n, x, a[maxn];
	cin >> n >> x;
	
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		mp[a[i]]++;	
	}
	for (int i = 1; i<=n; i++){
		if (mp[x-a[i]] > 0 && (x-a[i] != a[i])) res1 += mp[x-a[i]];
		else if (mp[x-a[i]] > 0 && (x-a[i] == a[i])) {
			res2 = res2 + mp[x-a[i]] - 1;
			mp[x-a[i]]--;
		}
	}
	res1 = res1/2;
	cout << res1 + res2;
}