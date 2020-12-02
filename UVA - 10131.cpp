       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

struct ele{
    int i, w, iq;
};

bool comp(ele& a, ele& b){
    return b.w > a.w;
}

int n = 1;
int mem[1001][1001];
vector<ele> v;

int dp(int idx, int last){
    if(idx == n){
        return 0;
    }

    int& ret = mem[idx][last];

    if(ret != -1)
        return ret;

    int ch1, ch2 = 0;
    ch1 = dp(idx+1, last);//skip
    if(v[idx].iq < v[last].iq && v[idx].w > v[last].w){
        ch2 = 1 + dp(idx+1, idx);//take
    }
    ret = max(ch1, ch2);

    return ret;
}

void out(int idx, int last){
    if(idx == n){
        return;
    }

    int ret = mem[idx][last];

    int ch1, ch2 = 0;
    ch1 = dp(idx+1, last);//skip
    if(v[idx].iq < v[last].iq){
        ch2 = 1 + dp(idx+1, idx);//take
    }

    if(ret == ch1){
        out(idx+1, last);
    }else{
        cout << v[idx].i << "\n";
        out(idx+1, idx);
    }

}

int main(){
//    o:
    init();

    memset(mem, -1, sizeof mem);
    v.push_back({-1, -1, 100000});

    int w, iq;
    for(; cin >> w >> iq; n++){
        v.push_back({n, w, iq});
    }
    sort(v.begin(), v.end(), comp);

    cout << dp(1, 0) << "\n";
    out(1, 0);

//    goto o;
    return 0;
}
