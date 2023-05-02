#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int maxn = 104;
bool invited[maxn][maxn];
ull a[maxn][maxn];
ull s1 = 0,s2 = 0, res = 0; 
int n, m, t;
int dx1[2] = {0, 0},
	dy1[2] = {-1, 1},
	
	dx2[2] = {-1, 1},
	dy2[2] = {0, 0};

void dfsx(int i, int j, int x){
	invited[i][j] = true;
	s1++;
	int i1, j1;
	for (int k = 0; k<=1; k++){
		i1 = i + dx1[k];
		j1 = j + dy1[k];
		if (i1 >= 1 && i1 <= n && j1 >=1 && j1 <= m && !(invited[i1][j1]) && a[i1][j1] == x) {
			dfsx(i1,j1,x);
		}
	}
	
}
void dfsy(int i, int j, int x){
	invited[i][j] = true;
	s2++;
	int i1, j1;
	for (int k = 0; k<=1; k++){
		i1 = i + dx2[k];
		j1 = j + dy2[k];
		if (i1 >= 1 && i1 <= n && j1 >=1 && j1 <= m && !(invited[i1][j1]) && a[i1][j1] == x) {
			dfsy(i1,j1,x);
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("f.inp", "r", stdin);
	//freopen("f.out", "w", stdout);

	cin >> n >> m >> t;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			s1 = 0; s2 = 0;
			if (!a[i][j]) continue;
			dfsx(i, j, a[i][j]);
			dfsy(i, j, a[i][j]);
			
			if (!(s1 >= t || s2 >= t)) res++;
			
			memset(invited, false, sizeof(invited));
		}
	}
		cout << res;
		
}
