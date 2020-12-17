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

int nVis;
void explore(vector<vector<int>>& adj, bool vis[], int u){
    vis[u] = true;
    nVis++;
    int n = adj.size(), v;
    for (int i = 0; i < (int)adj[u].size(); i++){
        v = adj[u][i];
        if(!vis[v]){
            explore(adj, vis, v);
        }
    }
}

int main(){
    o:
    init();
    bool flag;
    int n, m, u, v, p;
    while(cin >> n >> m && !(n == 0 && m == 0)){
        vector<vector<int>> adj(n);
        while(m--){
            cin >> u >> v >> p;
            adj[u-1].emplace_back(v-1);
            if(p == 2){
                adj[v-1].emplace_back(u-1);
            }
        }
        
        flag = true;
        for (int i = 0; i < n; i++){
            nVis = 0;
            bool vis[n] = {false};
            explore(adj, vis, i);
            if(n != nVis){
                cout << "0\n";
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "1\n";
    }

    #ifdef online_judge
        goto o;
    #endif // online_judge
    return 0;
}
