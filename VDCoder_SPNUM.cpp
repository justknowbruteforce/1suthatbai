/*
https://vinhdinhcoder.net/Problem/Details/5375
INPUT1
	6
OUTPUT1
	1
	
INPUT2
	125
OUTPUT2
	5
*/


#include <iostream>
#include <math.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int maxn = (1e5)+7;
bool f[maxn];

void sang(int n){
	for (int i = 2; i<=n; i++){
		f[i] = true;
	}
	f[1] = false;
	for (int i = 2; i<=sqrt(n); i++){
		if (f[i])
		for (int j = i*i; j<=n; j+=i){
			f[j] = false;
		}
	}
	
}
int main(){
	ull n;
	cin >> n;
	int res = 0;
	sang((int)sqrt(n) + 1);
	for (int i = 2; i<=sqrt(n); i++){
		if (f[i]) res++;
	}
	cout << res;
}
