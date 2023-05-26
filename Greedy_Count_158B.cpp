#include <stdio.h>
#include <string.h>
#define maxn int(1e5)+7
 
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void qsort(int a[], int l, int r){
	if (l>=r) return;
	int i = l, j = r;
	int m = a[(l+r)/2];
	while (i<=j){
		while (a[i]>m) i++;
		while (a[j]<m) j--;
		if (i<=j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	qsort(a, l, j);
	qsort(a, i, r);
}
 
int main(){
	//ios_base::sync_with_stdio(false);
	int n, a[maxn], f[maxn];
	scanf("%d", &n);
	memset(f,0,sizeof(f));
	for (int i = 1; i<=n; i++){
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	qsort(a, 1, n);
	int res = 0;
	for (int i = 1; i<=n; i++){
		int s = a[i];
		if (f[a[i]] > 0) {
			res++;
		    f[a[i]]--;
			for (int j = a[i]; j>=1; j--){
				while (s + j <= 4 && f[j] > 0 ){
					f[j]--;
					s += j;
			}
		}
	}
}
	printf("%d", res);
}
