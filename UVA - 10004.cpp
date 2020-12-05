       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool BFS(vector<vector<int>>& adj){
    int n = adj.size(), u, v;
    int color[n];
    memset(color, -1, sizeof color);

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++){
            v = adj[u][i];
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }else if(color[v] == color[u]){
                return 0;
            }
        }
    }

    return true;
}

int main(){
//    o:
    int n, m, u, v;
    while(scanf("%d", &n) && n != 0){
        scanf("%d", &m);
        vector<vector<int>> adj(n);
        while(m--){
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        printf(BFS(adj) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }
//    goto o;
    return 0;
}
