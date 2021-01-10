       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 100010;
int arr[N];
int segT[4 * N];

void build(int idx, int l, int r){
    if(l == r){
        segT[idx] = arr[l];
        return;
    }

    int m = l + (r-l)/2;
    build(2*idx + 1, l, m);
    build(2*idx + 2, m + 1, r);

    segT[idx] = segT[2*idx + 1] * segT[2*idx + 2];
}

int qu(int s, int e, int idx, int l, int r){
    if(l > e || r < s){
        return 1;
    }

    if(l >= s && r <= e){
        return segT[idx];
    }

    int m = l + (r-l)/2;
    return qu(s, e, 2*idx + 1, l, m) * qu(s, e, 2*idx + 2, m + 1, r);
}

void upd(int idx, int l, int r, int p, int v){
    if(l == r){
        segT[idx] = v;
        return;
    }

    int m = l + (r-l)/2;

    if(p <= m){
        upd(2*idx + 1, l, m, p, v);
    }else{
        upd(2*idx + 2, m + 1, r, p, v);
    }

    segT[idx] = segT[2*idx + 1] * segT[2*idx + 2];
}

int sign(int a){
    if(a > 0){
        return 1;
    }else if(a < 0){
        return -1;
    }else{
        return 0;
    }
}

char p(int a){
    return (a == 0 ? '0' : (a > 0 ? '+' : '-'));
}

int main(){
    o:
    init();

    char c;
    int n, k, a, b;
    while(cin >> n >> k){
        for (int i = 0; i < n; i++){
            cin >> a;
            arr[i] = sign(a);
        }

        build(0, 0, n-1);

        while(k--){
            cin >> c >> a >> b;
            if(c == 'C'){
                upd(0, 0, n-1, a-1, sign(b));
            }else{
                cout << p(qu(a-1, b-1, 0, 0, n-1));
            }
        }
        cout << "\n";
    }

    #ifdef online_judge
        cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
        goto o;
    #endif // online_judge
    return 0;
}
