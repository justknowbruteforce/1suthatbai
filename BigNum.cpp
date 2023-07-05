#include <bits/stdc++.h>

#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define el cout << '\n';
using namespace std;

const int maxn = (1e6) + 7;
const int INF = 2e9;
const ll ILL = 1e18;

int a[maxn];
string f[30];
string dp[100];
bool ss(string a, string b){
	if (a.length() < b.length()) return true;
	if (a.length() > b.length()) return false;
	for (int i = 0; i<a.length(); i++){
		if ((a[i] - '0') < (b[i] - '0')) return true;
		if ((a[i] - '0') > (b[i] - '0')) return false;
	}
	if (a[a.length()-1] == b[b.length()-1]) return true;
	return false;
}
string delete_zero(string s){
	int i = 0;
	string res = "";
	while (s[i] == '0') {
		i++;
	}
	for (int j = i; j<s.length(); j++) {
		res += s[j];
	}
	return res;
}
string ts(int n){
	string res = "";
	bool check = false;
	while (n != 0) {
		check = true;
		res = char(n%10 + 48) + res;
		n /= 10;
	}
	if (!check) return "0";
	return delete_zero(res);
}

string add(string a, string b){
	string res = "";
	while (a.length() < b.length()) a = '0' + a;
	while (b.length() < a.length()) b = '0' + b;
	int carry = 0;
	for (int i = a.length() - 1; i>=0; i--){
		carry = carry + (a[i] - '0') + (b[i] - '0');
		res = char(carry%10 + 48) + res;
		carry /= 10;
	}
	while (carry != 0) {
		res = char(carry%10 + 48) + res;
		carry /= 10;
	}
	return res;
}
string d2(string s){
	string res = "";
	int carry = 0;
	for (int i = 0; i<s.length(); i++){
		carry = carry * 10 + (s[i] - '0');
		res += ts(carry / 2);
		carry %= 2;
	}
	return delete_zero(res);
}
string mul(string a, int b){
	string res = "";
	int carry = 0;
	for (int i = a.length() - 1; i>=0; i--){
		carry = (a[i] - '0') * b + carry;
		res = char(carry%10 + 48) + res;
		carry /= 10;
	}
	while (carry != 0) {
		res = char(carry%10 + 48) + res;
		carry /= 10;
	}
	return delete_zero(res);

}
string muls(string a, string b){
	string res = "";

	string f = mul(a, b[b.length() - 1] - '0');
	dp[0] = f;
	int j = 1;
	string c = "0";
	for (int i = b.length()-2; i>=0; i--){
		dp[j] = delete_zero(add(dp[j-1], mul(a, b[i] - '0') + c));
		j++;
		c += '0';
	}

	return delete_zero(dp[j - 1]);
}
string mi1(string a){
	int i = a.length() - 1;
	if (a[i] > '0') a[i] = char(a[i] - 1);
	else {
		int b = 1;
		a[i] = '9';
		i--;
		while (b != 0 && i >= 0) {
			if (a[i] == '0') {
				a[i] = '9';
				i--;
			} else a[i] = char(a[i] - 1), b = 0;
		}
	}
	return delete_zero(a);
}
string d(string a, string b){
	string l = "1";
	string r = a;
	string res = "0";
	while (ss(l, r)) {
		string m = d2(add(l, r));
		//cout << l << " " << m << " " << r << endl;
		string tmp = muls(m, b);
		//cout << tmp << " " << a <<endl;
		if (ss(tmp, a)) {
			res = m;
			l = add(m, "1");
		} else {
			r = mi1(m);
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	f[0] = "1";
	f[1] = "1";
	for (int i = 2; i<=n; i++){
		f[i] = muls(f[i-1], ts(i));
	}
	cout << d(f[n], muls(f[k], f[n-k]));
}
