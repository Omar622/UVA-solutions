       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
//    o:
    string str;
    int crc;
    unsigned long m;
    const int g = 34943;
    while(getline(cin, str)){
        m = 0;
        if(str[0] == '#')
            break;

        for (int i = 0; i < (int)str.size(); i++){
            m <<= 8;
            m += str[i];
            m %= g;
        }
        m <<= 16;
        m %= g;
        crc = (g - m) % g;
        printf("%02X %02X\n", crc >> 8, crc % 256);

    }
//    goto o;
    return 0;
}

