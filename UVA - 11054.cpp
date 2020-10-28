       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    o:
    int n;
    ll ans, l_ans;
    while(cin>>n && n != 0){
        ans = l_ans = 0;
        scanf("%lld", &l_ans);
        for (int i = 1, x; i < n; i++){//sum of all = 0
            ans += abs(l_ans);
            scanf("%i", &x);
            l_ans += x;
        }
        ans += abs(l_ans);
        printf("%lld\n", ans);
    }
//    goto o;
    return 0;
}
