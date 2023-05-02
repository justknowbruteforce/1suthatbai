#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
using namespace std;
#define ll long long
#define maxn 5000005
// !accepted
ll green[maxn], red[maxn];
int r = 1, g = 1;

int tryred() {
	int cnt = 2;
	ll h = green[1];
	int i = 2, l = 2;
	while (i<=r) {
		while (red[i] >= h && i <=r) {
			i++;
		}	
	if (i<=r) {
		cnt++;
		h = red[i];
       
	} else return cnt;
	while (green[l] >= h && l <= g) {
		l++;
	}
	if (l <= g) {
		cnt++;
		h = green[l];
	} else return cnt;
	l++;
	i++;
	}
	return cnt; 	
}
int trygreen() {
	int cnt = 2;
	ll h = red[1];
	
	int i = 2, l = 2;
	
	while (i<=g) {
    while (green[i] >= h && i <= g) {
	i++;
	}
	if (i <= g) {
		cnt++;
		h = green[i];
	} else return cnt;
		while (red[l] >= h && l <=r) {
			l++;
		}	
	if (l<=r) {
		cnt++;
		h = red[l];
	} else return cnt;
	l++;
	i++;
	} 
	return cnt;	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("f.inp","r",stdin);
	//freopen("f.out","w",stdout);
	
	memset(red,0,sizeof(red));
	memset(green,0,sizeof(green));
	int n;
	ll x;
	
	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> x;
		if (x > 0) {
			red[r] = x;
			r++;
		} else {
			green[g] = abs(x);
			g++;
		}
	}
	g--; r--;
	
	sort(red+1,red+r+1, greater<ll> ());
	sort(green+1, green+g+1, greater<ll> ());
	
	if (red[1] > green[1]) {
		cout << tryred();
	} else cout << trygreen();
	
}