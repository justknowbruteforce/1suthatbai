#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = (1e3)+7;
vector<int> t;
vector<int> a[maxn];
bool f[maxn];
void dfs(int u){
	f[u] = true;
	t.push_back(u);
	for (int i:a[u]){
		if (!f[i]) dfs(i);
	}
}
void qsort(vector<int> &v, int l, int r){
	if (l>=r) return;
	int i = l, j = r;
	int m = v[(l+r)/2];
	while (i<j){
		while (v[i]<m) {
			i++;
		}
		while (v[j]>m){
			j--;
		}
		if (i<=j) {
			swap(v[i], v[j]);
			i++;
			j--;
		}
	}
	qsort(v, l, j);
	qsort(v, i, r);
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> res;
	int cnt = 0;
	for (int i=1; i<=m;i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(f,false,sizeof(f));
	for (int i = 1; i<=n; i++){
		if (!f[i]) {
			t.erase(t.begin(), t.end());
			dfs(i);
			qsort(t,0,t.size()-1);
			res.push_back(t);
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i=0; i<cnt; i++){
		cout << res[i].size() << " ";
		for (int j = 0; j<res[i].size()-1; j++){
			cout << res[i][j] << " ";
		}
		if (i==cnt-1) {
			cout << res[i][res[i].size()-1];
		} else cout << res[i][res[i].size()-1] << endl;
	}
}
