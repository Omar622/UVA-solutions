       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string a, b;
int mem[1000][1000];
int LCS(int i, int j){
    if(i >= (int)a.size() || j >= (int)b.size())
        return 0;
    int& ret = mem[i][j];
    if(ret != -1){
        return ret;
    }

    if(a[i] != b[j]){
        int ch1, ch2;
        ch1 = LCS(i+1, j);
        ch2 = LCS(i, j+1);
        ret = max(ch1, ch2);
    }else{
        ret = LCS(i+1, j+1) + 1;
    }

    return ret;
}


int main() {
//    o:
    while(getline(cin, a) && getline(cin, b)){
        memset(mem, -1, sizeof mem);
        printf("%i\n", LCS(0, 0));
    }
//    goto o;
    return 0;
}
