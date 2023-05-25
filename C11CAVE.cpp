#include <iostream>
using namespace std;
const int maxn = 500006;
int n, h, f[maxn], t;
int main(){
    cin >> n >> h;
    for (int i = 1; i<=n; i++){
        int l, r, k;
        cin >> k;
        if (i%2){
            l = 1;
            r = k;
        } else {
            l = h-k+1;
            r = h;
        }
        f[l]++;
        f[r+1]--;
    }
    for (int i = 1; i<=h; i++){
        f[i] += f[i-1];
        if (f[i]<n) {
            n = f[i];
            t = 1;
        } else if (f[i]==n){
            t++;
        }

    }
    cout << n << " " << t;
    return 0;
}
