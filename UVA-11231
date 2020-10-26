        /* Do it! */
       /*  OMAR  */
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    long long a, b, c;

    while(cin>>a>>b>>c){
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        if(a == 8 && b == 8 && c == 1){
            printf("1\n");
        }else{
            a = (a-7)*(b-7);
            printf("%lld\n", a % 2 == 0 ? a / 2 : (c ? (a + 1) / 2 : a / 2));
        }

    }
    return 0;
}
