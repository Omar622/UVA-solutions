       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
using namespace std;
#define siz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define PI acos(-1.0)
typedef long long ll;

bool isV(char c){
    return c == 'i' || c == 'o' || c == 'e' || c == 'a' || c == 'u';
}

bool isEs(string a){
    bool flag = a.back() == 'o' || a.back() == 's' || a.back() == 'x';
    if(flag) return true;
    if(a.back() == 'h' && siz(a) > 1){
        return a[siz(a)-2] == 'c' || a[siz(a)-2] == 's';
    }
    return false;
}

int main(){
    FIO
    o:
        
    int n, l;
    string a, b;
    map<string, string> mp;
    cin >> l >> n;

    while(l--){
        cin >> a >> b;
        mp[a] = b;
    }

    string arr[n];
    for (int i = 0; i < n; ++i){
        cin >> a;
        if(mp.find(a) != mp.end()){
            arr[i] = mp[a];
        }else{
            if(a.back() == 'y' && !isV(a[siz(a)-2])){
                arr[i] = a.substr(0, siz(a)-1) + "ies";
            }else if(isEs(a)){
                arr[i] = a + "es";
            }else{
                arr[i] = a + "s";
            }
        }
    }

    for (int i = 0; i < n; ++i){
        cout << arr[i] << "\n";
    }

//    goto o;
    return 0;
}
