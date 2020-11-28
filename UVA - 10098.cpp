       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
}

int main(){
//    o:
    init();
    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        sort(str.begin(), str.end());
        do{
            cout<<str<<"\n";
        }while(next_permutation(str.begin(), str.end()));
        cout<<"\n";
    }
//    goto o;
    return 0;
}
