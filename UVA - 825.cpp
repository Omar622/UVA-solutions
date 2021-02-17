       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
using namespace std;
#define siz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define FIO cin.tie(0), cin.sync_with_stdio(0);
typedef long long ll;

const int N = 102;
int n, d, S[N];

int main(){
    FIO
    o:

    string line;
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin.ignore();
        
        int arr[n][m];
        memset(arr, 0, sizeof arr);

        for (int k = 0; k < n; ++k){
            int i, j;
            getline(cin, line);
            stringstream ss(line);
            ss >> i;
            i--;
            while(ss >> j){
                j--;
                arr[i][j] = -1;
            }
        }

        arr[0][0] = 1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(i == 0 && j == 0 || arr[i][j] == -1) continue;
                if(i == 0){
                    arr[i][j] = max(arr[i][j-1], 0);
                 }else if(j == 0){
                    arr[i][j] = max(arr[i-1][j], 0);
                 }else{
                    arr[i][j] = max(arr[i-1][j], 0) + max(arr[i][j-1], 0);
                 }
            }
        }

        cout << arr[n-1][m-1] << "\n";
        if(t) cout << "\n";
    }

//    goto o;
    return 0;
}
