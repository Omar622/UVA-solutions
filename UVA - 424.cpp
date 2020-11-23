       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string operator+(string x, string y){
    string res;
    int r = 0, res0;
    if(y.size() > x.size())
        swap(x, y);

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    y.insert(y.size(), string(x.size()-y.size(), '0'));

    for(unsigned int i = 0; i < x.size(); i++){
        string a, b;
        a = x[i],
        b = y[i];
        res0 = stoi(a) + stoi(b) + r;
        r = 0;
        if(res0 > 9){
            res0 %= 10;
            res.insert(0, to_string(res0));
            r = 1;
        }else{
            res.insert(0, to_string(res0));
        }
    }
    if(r != 0)
        res.insert(0, to_string(r));
    return res;
}

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
}

int main(){
//    o:
    init();
    string a, res = "0";
    while(cin>>a && a != "0"){
        res = a + res;
    }
    cout<<res<<"\n";
//    goto o;
    return 0;
}
