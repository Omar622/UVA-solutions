       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n, m, u, v;
    while(cin >> n >> m){
        map<int, vector<int>>adj;
        for (int i = 0; i < n; i++){
            cin >> u;
            adj[u-1].emplace_back(i+1);
        }
        for (int i = 0; i < m; i++){
            cin >> v >> u;
            cout << (v > adj[u-1].size() ? 0 : adj[u-1][v-1]) << "\n";
        }
    }
    return 0;
}
