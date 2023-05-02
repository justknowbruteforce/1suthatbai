#include <iostream>
#include <map>
#include <string.h>
using namespace std;
#define ll long long
#define maxn 100005
int main(){
	int n;
	cin >> n;
	ll a[maxn], pre_sum[maxn];
	memset(pre_sum,0,sizeof(pre_sum));
	map <ll,ll> vt;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		pre_sum[i] = pre_sum[i-1] + a[i];
		if (vt[a[i]] == 0) vt[a[i]] = i;
	}
	map <ll, ll> current_sum;
	ll maxx = -1e11, tmp, res = -2e11;
	for (int i = 1; i<=n ; i++){
		if (i > vt[a[i]] && vt[a[i]] != 0) {
			tmp = pre_sum[i] - pre_sum[vt[a[i]] - 1];
			res = max(res,tmp);
			if (current_sum[a[i]] <= 0) current_sum[a[i]] = tmp;
			
			else current_sum[a[i]] = current_sum[a[i]] + tmp - a[i];
			//cout << i << " - " << vt[a[i]] << " : " << tmp << " " << current_sum[a[i]] << endl; 
			res = max(res,current_sum[a[i]]);
			vt[a[i]] = i;	
		}
	}
	cout << res;
	
	
}