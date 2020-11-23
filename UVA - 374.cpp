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
    return res%m;
}

int main(){
//    o:
    string line;
    ll b, p, m;

    while(cin>>b>>p>>m){//there is line in the end of one of test cases
        printf("%lld\n", power(b, p, m));

        if(getline(cin, line)){
            cin.ignore();
        }else
            break;
    }
//    goto o;
    return 0;
}
