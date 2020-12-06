       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isCycle = false;
int p = 0;
vector<int>toplg;

void explore(vector<vector<int>>& adj, int flags[], int u){
    int v;
    flags[u] = 1;//visited

    for (int i = 0; i < (int)adj[u].size() && !isCycle; i++){
        v = adj[u][i];
        if(flags[v] == 1){//visited
            isCycle = true;
        }else if(flags[v] == 0){// not visited
            explore(adj, flags, v);
        }
    }

    toplg.emplace_back(u+1);
    flags[u] = 2;//post-ordered
}


void DFS(vector<vector<int>>& adj){
    int n = adj.size();
    int flags[n] = {0};

    for (int i = 0; i < n && !isCycle; i++){
        if(flags[i] == 0){// not visited
            explore(adj, flags, i);
        }
    }
}

int main(){
//    o:
    int n, m, u, v;
    while(scanf("%i%i", &n, &m) && !(n == 0 && m == 0)){
        vector<vector<int>> adj(n);
        while(m--){
            scanf("%i%i", &v, &u);
            adj[u-1].emplace_back(v-1);//directed
        }

        DFS(adj);

        if(isCycle){
            printf("IMPOSSIBLE\n");
            isCycle = false;
        }else{
            for (int i = 0; i < (int)toplg.size(); i++){
                printf("%i\n", toplg[i]);
            }
        }
        
        p = 0;
        toplg.clear();
    }

//    goto o;
    return 0;
}

