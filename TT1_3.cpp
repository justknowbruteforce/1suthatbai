#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

const int maxn = 1004;
int a[maxn], b[maxn], c[maxn], n;
map<int, int> f;
int find(int a[], int l, int r, int x){
	while (l<=r){
		int m = (l+r)/2;
		if (a[m]==x) return m;
		else if (a[m] > x) r = m-1;
		else l = m+1;
	}
	return 0;
}
int main(){

	cin >> n;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> b[i];
	for (int i = 1; i<=n; i++){
		cin >> c[i]; f[c[i]]++;
	}
	sort(c+1, c+n+1);
	int res = 0;
	f[0] = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			int d1 = max(a[i], b[j]);
			int d2 = min(a[i], b[j]);
			int sqr = sqrt((d1*d1) + (d2*d2));
			if (sqr*sqr == ((d1*d1) + (d2*d2))) {
				int k = find(c, 1, n, sqr);
				//cout << sqr << " ";
				res += f[c[k]];
			}
			sqr = sqrt((d1*d1) - (d2*d2));
			if (sqr*sqr == ((d1*d1) - (d2*d2))) {
				int k = find(c, 1, n, sqr);
				//cout << sqr << " ";
				res += f[c[k]];
			}	
		}
	}
	cout << res;	
}
