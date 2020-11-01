      /*  Do it! */
     /*  OMAR   */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    o:
    int n, c;
    while(cin>>n){
        c = 0;
        for (int i = 1; ; i = (i * 10 + 1) % n){
            c++;
            if(i % n == 0){
                printf("%i\n", c);
                break;
            }
        }
    }
//    goto o;
    return 0;
}
