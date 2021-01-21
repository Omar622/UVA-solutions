       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    o:
    init();

    char c;
    int t, n;
    cin >> t;
    for (int o1 = 1; o1 <= t; o1++){
        cin >> n;
        char arr[n][n];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }


        cout << "Case " << o1 << ":\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                c = 'A';
                if(arr[i][j] == '.'){
                    while((i+1 < n && arr[i+1][j] == c) || (i-1 >= 0 && arr[i-1][j] == c) || (j+1 < n && arr[i][j+1] == c) || (j-1 >= 0 && arr[i][j-1] == c))
                        c++;
                    arr[i][j] = c;
                }
                cout << arr[i][j];
            }
            cout << "\n";
        }

    }

    #ifdef online_judge
        goto o;
    #endif // online_judge
    return 0;
}
