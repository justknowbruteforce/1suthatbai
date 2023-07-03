// https://oj.vnoi.info/problem/fcb053_numrect
// Code by HuyPE
#include <iostream>
using namespace std;
const int maxn = 2e4 + 7;
unsigned long long f[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f[0] = 0;
	for (int i = 1; i <= maxn; i++){
		f[i] = f[i-1] + i;
	}
	int t;
	cin >> t;
	while (t--){
		int n,m; 
		cin >> n >> m;
		cout << (unsigned long long)f[n] * f[m] << "\n";
	}
}
