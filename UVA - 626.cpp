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

bool checkIdentical(set<vector<int>>& res, int u1, int u2, int u3){
    if((u1 < u2 && u2 < u3) || (u1 > u2 && u2 > u3)){
        return res.find({u1+1, u2+1, u3+1}) == res.end();
    }
    if((u2 < u3 && u3 < u1) || (u2 > u3 && u3 > u1)){
        return res.find({u2+1, u3+1, u1+1}) == res.end();
    }
    return res.find({u3+1, u1+1, u2+1}) == res.end();
}

void add(set<vector<int>>& res, int u1, int u2, int u3){
    if((u1 < u2 && u2 < u3) || (u1 > u2 && u2 > u3)){
        res.insert({u1+1, u2+1, u3+1});
    }else if((u2 < u3 && u3 < u1) || (u2 > u3 && u3 > u1)){
        res.insert({u2+1, u3+1, u1+1});
    }else{
        res.insert({u3+1, u1+1, u2+1});
    }
}

int main(){
    o:
    init();
    int n, u1, u2, u3;
    while(cin >> n){
        set<int> adj[n];
        set<vector<int>> res;
        for (int i = 0, x; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> x;
                if(x == 1){
                    adj[i].emplace(j);
                }
            }
        }

        for (int i = 0; i < n; i++){//O(n^3 log(n))
            u1 = i;
            for(set<int>::iterator it2 = adj[u1].begin(); it2 != adj[u1].end(); it2++){
                u2 = *it2;
                if(u2 == u1) continue;
                for (set<int>::iterator it3 = adj[u2].begin(); it3 != adj[u2].end(); it3++){
                    u3 = *it3;
                    if(u2 == u3 || u1 == u3) continue;
                    if(adj[u3].find(u1) != adj[u3].end()){
                        if(checkIdentical(res, u1, u2, u3)){//check identical
                            add(res, u1, u2, u3);
                        }
                    }
                }
            }
        }

        for(set<vector<int>>::iterator it = res.begin(); it != res.end(); it++){
            vector<int> temp = *it;
            cout << temp[0] << " " << temp[1] << " " << temp[2] << "\n";
        }
        cout << "total:" << res.size() << "\n\n";
    }

    #ifdef online_judge
        goto o;
    #endif // online_judge
    return 0;
}
