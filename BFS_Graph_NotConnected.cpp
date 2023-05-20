#include <iostream>
#include <queue>
#include <string.h>
#define maxn 104
using namespace std;
vector<int> a[maxn];
bool f[maxn];
void bfs(int u){
	queue<int> q;
	q.push(u);
	f[u] = true;
	while (!q.empty()){
		int v = q.front();
		cout << v << endl;
		q.pop();
		for (int i:a[v]){
			if (!f[i]){ 
			f[i] = true;
			q.push(i);
			}	
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i<=m; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(f,false,sizeof(f));
	for (int i = 1; i<=n; i++){
		if (!f[i]) bfs(i);
	}
}

