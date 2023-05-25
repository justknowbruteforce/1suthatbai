#include <iostream>
#include <string.h>
#include <math.h>
#define ull unsigned long long
using namespace std;
const int maxn = 1002;
ull a[maxn], b[maxn];
int f[maxn][maxn];
ull max(ull a, ull b){
    if (a>b) return a;
    return b;
}

ull sqrt3(ull x) {
	ull l = 1, r = 2154435, a;
	while (l <= r) {
		ull m = (l+r)/2;
		if (m*m*m <= x) {
			a = m;
			l = m+1;
		} else r = m-1;
	}
	return a;
}
bool prime(ull x){
    if (x<2) return false;
    if (x==2) return true;
    ull t = sqrt3(x);
    for (int i = 2; i<6 && i*i < x; i++) {
        if (!x%i) return false;
    }
    for (int k = 1; 6*k+1 <= t; k++){
        if (x%(6*k+1) == 0 || x%(6*k+5)==0) return false;
    }
    return true;
}
bool check(ull x){
    if (!x) return false;
    ull sqr = sqrt(x);
    if (sqr*sqr == x) return true;
    sqr = sqrt3(x);
    if (sqr*sqr*sqr == x && prime(sqr)) return true;
    return false;
}
void inp(ull *a, int &n){
    string s;
    getline(cin, s);
    s += ' ';
    ull x = 0;
    for (int i = 0; i<=s.length(); i++){
        if (s[i] == ' '){
            if (check(x)){
                n++;
                a[n] = x;
            }
            x = 0;
        } else {
            x = x*10 + (s[i] - '0');
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0;
    inp(a, n);
    inp(b, m);
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if (a[i]==b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    }
    cout << f[n][m];
}
