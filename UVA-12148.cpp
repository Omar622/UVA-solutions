        /* Do it! */
       /*  OMAR  */
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    bool isLeap;
    int n, d, m, y, c, d0, m0, y0, c0, num , sum;
    int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(cin>>n && n != 0){
        num = sum = 0;
        d0 = m0 = y0 = c0 = 0;
        for (int i = 0; i < n; i++){
            cin>>d>>m>>y>>c;
            isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
            if(y0 == y && m0 == m && abs(d0-d) == 1 || 
            y0 == y && abs(m0-m) == 1 && abs(d0-d) == ((isLeap && min(m0, m) == 2) ? M[min(m0, m)-1] : M[min(m0, m)-1]-1) ||
            abs(y0-y) == 1 && abs(m0-m) == 11 && abs(d0-d) == 30){
                num++;
                sum += c-c0;
            }
            y0 = y; m0 = m; d0 = d; c0 = c;
        }
        cout<<num<<" "<<sum<<endl;
    }
    return 0;
}
