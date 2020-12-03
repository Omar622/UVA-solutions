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

struct targ{
    int x, y, p;
};
targ arr[1002];
double mem[1002][1002];
int n;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double dp(int idx, int last){
    if(idx == n+2)
        return 0.0;

    double &ret = mem[idx][last];

    if(ret == ret)// !nan
        return ret;

    double ch1, ch2;
    ch1 = arr[idx].p + dp(idx+1, last);//take penalty
    ch2 = 1 + dist(arr[idx].x, arr[idx].y, arr[last].x, arr[last].y) + dp(idx+1, idx);//take target

    ret = min(ch1, ch2);

    return ret;
}

int main(){
//    o:
    init();
    
    int x, y, p;
    arr[0] = {0, 0, 1000000000};//must take

    while(cin >> n && n != 0){
        memset(mem, -1, sizeof mem);//nan

        for (int i = 1; i <= n; i++){
            cin >> x >> y >> p;
            arr[i] = {x, y, p};
        }
        arr[n+1] = {100, 100, 1000000000};//must take

        cout << fixed << setprecision(3) << dp(1, 0) << "\n";
    }
//    goto o;
    return 0;
}
