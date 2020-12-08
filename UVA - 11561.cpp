       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int w, h;
int explore(vector<vector<char>>& mp, int i, int j, vector<vector<bool>>& vis){
    vis[i][j] = true;

    if(mp[i][j] == '#' || (mp[i-1][j] == 'T' || mp[i+1][j] == 'T' || mp[i][j+1] == 'T' || mp[i][j-1] == 'T'))
        return mp[i][j] == 'G';

    int u = 0, d = 0, l = 0, r = 0;

    if(!vis[i-1][j])
        u = explore(mp, i-1, j, vis);
    if(!vis[i+1][j])
        d = explore(mp, i+1, j, vis);
    if(!vis[i][j+1])
        l = explore(mp, i, j+1, vis);
    if(!vis[i][j-1])
        r = explore(mp, i, j-1, vis);

    return (mp[i][j] == 'G') + u + d + l + r;
}

int main(){
//    o:
    int bi, bj;
    while(cin >> w >> h){
        vector<vector<char>> mp(h, vector<char>(w));
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                scanf(" %c", &mp[i][j]);
                if(mp[i][j] == 'P'){
                    bi = i;
                    bj = j;
                }
            }
        }
        vector<vector<bool>> vis(h, vector<bool>(w, false));
        printf("%i\n", explore(mp, bi, bj, vis));
    }
//    goto o;
    return 0;
}

