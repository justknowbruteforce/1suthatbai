/*
	INPUT
	10
	1 3 6 2 8 3 2 1 3 8
	OUTPUT
	2
*/
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
const ll INF = (1e10)+7;
const int maxn = (1e6)+7;
ll a[maxn];
ll maxx(ll a, ll b){
	if (a>b) return a;
	return b;
}
ll minx(ll a, ll b){
	if (a<b) return a;
	return b;
}
int main(){
	int n;
	cin >> n;
	ll maxx = -INF, minx = INF;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		maxx = max(a[i], maxx);
		minx = min(a[i], minx);
	}
	if (maxx == minx) {
		cout << 1;
		return 0;
	}
	int res = 1e8;
	bool check_max = false;
	bool check_min = false;
	int vtmin, vtmax;
	for (int i = 1; i<=n; i++){
		if ((a[i]==minx && !check_max) || (check_max && !check_min && a[i]==minx)) {
			vtmin = i;
			check_min = true;
		}
		if ((a[i]==maxx && !check_min) || (check_min && !check_max && a[i]==maxx)) {
			vtmax = i;
			check_max = true;
		}
		if (check_max && check_min){
			res = min(abs(vtmax-vtmin)+1, res);
			if (vtmax > vtmin) check_min = false;
			else check_max = false;
		}
	}
	cout << res;
}
