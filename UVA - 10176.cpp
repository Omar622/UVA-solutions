      /*  Do it! */
     /*  OMAR   */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 131071;

void pre(int arr[]){
    int b = 2;
    arr[0] = 1;
    for (int i = 1; i <= 10000; i++){
        arr[i] = (arr[i-1] * 2) % mod;
    }

}

int main() {
//    o:
    int p2mod[10005];
    pre(p2mod);

    bool flag = true;
    string str, temp;
    ll num;
    while(true){
        if(flag){
            if(cin>>str);
            else break;
        }else{
            if(cin>>temp);
            else break;
            str += temp;
        }
        flag = true;
        if(str[str.size()-1] != '#'){
            flag = false;
            continue;
        }

        num = 0;
        int cnt = 0;
        for (int i = str.size()-1; i >= 0; i--){
            if(str[i] == '1'){
                num = (num + p2mod[cnt]) % mod;
            }
            cnt++;
        }
        printf(num % mod ? "NO\n" : "YES\n");
    }
//    goto o;
    return 0;
}

