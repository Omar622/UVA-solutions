       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    o:
    int n, m, j;
    ll ans;
    while(cin>>n>>m){
        if(n == 0 && m == 0)
            break;
        int heads[n], guards[m];
        ans = j = 0;
        for (int i = 0; i < n; i++){
            scanf("%i", &heads[i]);
        }

        for (int i = 0; i < m; i++){
            scanf("%i", &guards[i]);
        }
        
        sort(heads, heads+n);
        sort(guards, guards+m);
        for(int i = 0; i < m; i++){
            if(guards[i] >= heads[j]){
                ans += guards[i];
                j++;
                if(j == n)
                    break;
            }
        }
        if(j < n)
            printf("Loowater is doomed!\n");
        else
            printf("%lld\n", ans);
    }
//    goto o;
    return 0;
}


//________________________________________________________________________________
//    int n, m;
//    ll ans;
//    bool canKill;
//    while(cin>>n>>m){
//        if(n == 0 && m == 0){
//            break;
//        }
//        canKill = true;
//        ans = 0;
//        int heads[n];
//        for (int i = 0, x; i < n; i++) {
//            scanf("%i", &x);
//            heads[i] = x;
//        }
//        map<int, int>guards;
//        for (int i = 0, x; i < m; i++) {
//            scanf("%i", &x);
//            guards[x]++;
//        }
//        if(n > m){
//            printf("Loowater is doomed!\n");
//            canKill = false;
//        }else{
//            map<int, int>::iterator it;
//            for (int i = 0; i < n; i++){
//                it = guards.upper_bound(heads[i]);
//                if(it == guards.end())
//                    it--;
//                if(it->first < heads[i]){
//                    printf("Loowater is doomed!\n");
//                    canKill = false;
//                    i = n;
//                }else{
//                    it--;
//                    if(it->first >= heads[i] && it->second > 0){
//                        ans += it->first;
//                        (it->second)--;
//                    }else{
//                        it++;
//                        while(it!= guards.end() && it->second <= 0){
//                            it++;
//                        }
//                        if(it != guards.end()){
//                            ans += it->first;
//                            (it->second)--;
//                        }else{
//                            printf("Loowater is doomed!\n");
//                            canKill = false;
//                            i = n;
//                        }
//                    }
//                }
//            }
//        }
//        if(canKill)
//            printf("%lld\n", ans);
//    }
