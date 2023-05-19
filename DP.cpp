#include <iostream>
#include <algorithm>
#define maxn int(1e5+7)
#define ll long long
#define ull unsigned long long
using namespace std;
void r_faster(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
struct dt{
	int x, y, id;
};
void fsort(dt a[], int l, int r){
	if (l >= r) return;
	int i = l, j = r;	
	int m = a[(l+r)/2].x;
	while (i < j){
		while (a[i].x < m) i++;
		while (a[j].x > m) j--;
		if (i <= j)	{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	fsort(a, l, j);
	fsort(a, i, r);
}
int tknp(dt a[], int l, int r, int k) {
	int res = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m].x <= k) {
			res = m;
			l = m + 1;
		}
		if (a[m].x > k) {
			r = m - 1;
		} 
	} 	
	return res;
}
int main(){
	r_faster();
	int n, s, f;
	cin >> n >> s >> f;
	dt a[maxn];
	for (int i = 1; i<=n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	fsort(a,1,n);
	vector<int> res;
	int j = 1, fidx = s,
	yMax = a[1].y,
	idMax = a[1].id;
	a[0].id = 0;
	bool check = false;
	while (!check) {
		int idx = tknp(a, j, n, fidx);
		bool found = false;
		for (int i = j; i<=idx; i++){
			if (a[i].id) {
				found = true;
				if (yMax < a[i].y) {
					yMax = a[i].y;
					idMax = a[i].id;
				}
				a[i].id = 0;
			}

		}		
		if (!found) break;
		res.push_back(idMax);
		if (yMax >= f) {
			check = true;
			break;
		} else {
			fidx = yMax;
			j = idx;
		}		
	}
	if (!check) cout << -1;
		else {
			cout << res.size() << endl;
			for (auto t:res) {
				cout << t << " ";
			}
		}	
	return 0;
}