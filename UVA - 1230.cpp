       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll power(ll b, int p, int m) {
    ll res = 1;
    while(p > 0){//O(log2n)
        if(p % 2 != 0){
            res *= b;
            res %= m;
        }
        p >>= 1,
        b *= b;
        b %= m;
     }
    return res;
}

int main(){
//    o:
    int t, x, n, y;
    scanf("%i", &t);
    while(t--){
        scanf("%i%i%i", &x, &y, &n);
        printf("%lld\n", power(x, y, n));
    }
    scanf("%i", &t);
//    goto o;
    return 0;
}
