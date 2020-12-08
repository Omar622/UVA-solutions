       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
//    o:
    bool anyOneWake;
    int s, m, c, nYears;
    while(cin >> s){
        nYears = 0;
        scanf("%i", &m);
        vector<char> adj[26];
        vector<char> willWake;
        set<char> wake;

        char u, v;
        scanf(" %c", &u);
        wake.emplace(u);
        scanf(" %c", &u);
        wake.emplace(u);
        scanf(" %c", &u);
        wake.emplace(u);

        while(m--){
            scanf(" %c%c", &u, &v);
            adj[u - 'A'].emplace_back(v);
            adj[v - 'A'].emplace_back(u);
        }

        anyOneWake = true;
        while(anyOneWake){
            anyOneWake = false;
            for (int i = 0; i < 26; i++){
                c = 0;
                if(wake.find((char)(i + 'A')) == wake.end()){//sleep
                    for (int j = 0; j < (int)adj[i].size() && c != 3; j++){
                        if(wake.find(adj[i][j]) != wake.end()){//awake
                            c++;
                        }
                    }
                    if(c == 3){
                        willWake.emplace_back((char)('A' + i));
                        anyOneWake = true;
                    }
                }
            }
            
            while(!willWake.empty()){//clear willWake
                wake.emplace(willWake.back());
                willWake.pop_back();
            }
            nYears++;
        }

        if((int)wake.size() == s){
            printf("WAKE UP IN, %i, YEARS\n", nYears-1);
        }else{
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
    }


//    goto o;
    return 0;
}
