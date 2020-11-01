      /*  Do it! */
     /*  OMAR   */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll lcm (ll a, ll b){
    return (a*b) / __gcd(a, b);
}

void inc_exe(vector<ll>&arr, bool temp[], ll n, ll t, ll r, ll& res){
    for (int i = 0; i < 2; i++){
        temp[n-t] = i;
        if(t != 1){
           inc_exe(arr, temp, n, t-1, r, res);
        }else{
            ll l_res = 1, num = 0, sign;
            for (int j = 0; j < n; j++){
                if(temp[j]){
                    l_res = lcm(l_res, arr[j]),
                    num++;
                }
            }
            l_res = r / l_res;
            if(num){
                sign = num % 2 ? 1 : -1;
                res += sign * l_res;
            }
        }
    }
}

int main() {
//    o:
    ll n, m, a;
    ll res, LCM;
    while(cin>>n>>m){
        res = 0;
        vector<ll>num_m;
        for (int i = 0; i < m; i++){
            scanf("%lld", &a);
            num_m.emplace_back(a);
        }
        bool temp[(int)num_m.size()] = {false};
        inc_exe(num_m, temp, (int)num_m.size(), (int)num_m.size(), n, res);
        printf("%lld\n", n-res);
    }
//    goto o;
    return 0;
}

