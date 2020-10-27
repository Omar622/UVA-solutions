       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll power2[55];

void pre(){
    power2[0] = 1;
    for (int i = 1; i < 55; i++){
        power2[i] = power2[i-1]*2;
    }
}

ll toBinary(string& str){
    ll res = 0;
    for (int i = str.size()-1, j = 0; i >= 0; i--, j++){
        if(str[i] == '1'){
            res += power2[j];
        }
    }
    return res;
}


int main() {
//    o:
//get min value and max "101"
    int t, p, q;
    scanf("%i", &t);
    pre();
    while(t--){
        string str = "";
        scanf("%i%i", &p, &q);
        while(p >= 2 && q > 0){
            str += "101";
            p -= 2;
            q--;
        }

        if(p > 0 && q > 0){
            str.insert(0, "1");
            p--, q--;
        }

        while(p > 0){
            str += "1";
            p--;
        }
        printf("%lld\n", toBinary(str));
    }
//    goto o;
    return 0;
}

