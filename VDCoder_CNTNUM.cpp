//https://vinhdinhcoder.net/Problem/Details/5378
#include <iostream>
#define llu unsigned long long
using namespace std;
llu gcd(llu a, llu b){
	if (!b) return a;
	return gcd(b, a%b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	llu a, b, c, d;
	cin >> a >> b >> c >> d;
	llu g = c * d /gcd(c, d);
	g = (b/g - (a-1)/g);
	llu m = (b/c - (a-1)/c) + (b/d - (a-1)/d) - g;
	cout << (llu)(b - a + 1) - m;

}
