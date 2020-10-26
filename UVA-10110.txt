        /* Do it! */
       /*  OMAR  */
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long x, sqr;
    while(cin>>x && x != 0){
        sqr = sqrt(x);
        printf(sqr * sqr == x ? "yes\n" : "no\n");
    }
    return 0;
}
