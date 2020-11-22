     /* Do it! */
    /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isShip, isX;

void DFS(string arr[], int n, vector<vector<bool>>&visited, int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < n){
        if(!visited[i][j] && arr[i][j] == 'x')
           isX = true;
        if(isX && arr[i][j] != '.'){
            visited[i][j] = true;
            isShip = true;
            DFS(arr, n, visited, i+1, j);
            DFS(arr, n, visited, i, j+1);
        }
    }
}

int main(){
//    o:
    int t, n, c;
    scanf("%i", &t);
    for (int T = 1; T <= t; T++){
        c = 0;
        scanf("%i", &n);
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        string arr[n];
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(!visited[i][j]){
                    isX = false;
                    isShip = false;
                    DFS(arr, n, visited, i, j);
                    if(isShip)
                        c++;
                }
            }
        }
        printf("Case %i: %i\n", T, c);
    }
//    goto o;
    return 0;
}
