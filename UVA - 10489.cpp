      /*  Do it! */
     /*  OMAR   */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//problem statement in B descriptoin "it means that each a(i) box has a(i+1) boxes, 1 < i < B"

int main() {
//    o:
    int t, n, b, bn, a;
    ll mult, sum;
    scanf("%i", &t);
    while(t--){
        sum = 0;
        scanf("%i%i", &n, &b);
        while(b--){
            scanf("%i", &bn);
            mult = 1;
            while(bn--){
                scanf("%i", &a);
                mult = (mult*a) % n;
            }
            sum = (sum + mult) % n;
        }
        printf("%i\n", sum);
    }
//    goto o;
    return 0;
}
