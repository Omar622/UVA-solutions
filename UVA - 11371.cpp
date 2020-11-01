      /*  Do it! */
     /*  OMAR   */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll toNum(string str){
    int z = 0;
    string zero = "";
    for (int i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            z++;
            zero += "0";
        }else{
            break;
        }
    }
    str = str[z] + zero + str.substr(z+1);
    return stoll(str);
}

int main() {
//    o:
    string n;
    ll a, b;
    while(cin>>n){
        sort(n.begin(), n.end());
        a = toNum(n);
        reverse(n.begin(), n.end());
        b = stoll(n);
        printf("%lld - %lld = %lld = 9 * %lld\n", b, a, b-a, (b-a)/9);
    }
//    goto o;
    return 0;
}
