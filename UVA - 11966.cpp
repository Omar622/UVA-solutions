       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

double distance(double x0, double y0, double x, double y){
    return sqrt((x0-x)*(x0-x) + (y0-y)*(y0-y));
}

void explore(pair<double, double> star[], bool vis[], int n, int u, double d){
    vis[u] = true;
    double x0, y0, x, y;
    x0 = star[u].first;
    y0 = star[u].second;
    for (int i = 0; i < n; i++){
        x = star[i].first;
        y = star[i].second;
        if(!vis[i] && distance(x0, y0, x, y) <= d){
            explore(star, vis, n, i, d);
        }
    }
}

int DFS(pair<double, double> star[], int n, double d){
    int SCC = 0;
    bool vis[n] = {false};
    for (int i = 0; i < n; i++){
        if(!vis[i]){
            explore(star, vis, n, i, d);
            SCC++;
        }
    }
    return SCC;
}

int main(){
    o:
    int t;
    scanf("%d", &t);
    for (int o = 1; o <= t; o++){
        int n;
        double d;
        scanf("%d%lf", &n, &d);
        pair<double, double> star[n];
        for (int i = 0; i < n; i++){
            scanf("%lf%lf", &star[i].first, &star[i].second);
        }
        printf("Case %d: %d\n", o, DFS(star, n, d));
    }


    #ifdef online_judge
        goto o;
    #endif // online_judge
    return 0;
}
