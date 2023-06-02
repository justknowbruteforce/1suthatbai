/*
https://vinhdinhcoder.net/Problem/Details/5376
INPUT
	4 2
	1 2 3 4
OUTPUT
	9
*/
#include <iostream>
using namespace std;
const int maxn = (1e5)+7;
int a[maxn];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
	}
	a[0] = 0;
	a[n+1] = 0;
	unsigned long long sum = 0;
	for (int i = 1; i<=n+1; i++){
		int k = m;
		if (a[i-1] <= k){
			sum += a[i-1];
			k -= a[i-1];
			a[i-1] = 0;
		} else {
			sum += k;
			k = 0;
			a[i-1] -= k;
		}
		if (a[i] <= k){
			sum += a[i];
			a[i] = 0;
		} else {
			sum += k;
			a[i] -= k;
		}
	}
	cout << sum;
}
	
