     /* Do it! */
    /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool willNotBroke(char c){
    return c == 'I' || c == 'E' || c == 'H' || c == 'O' || c == 'V' || c == 'A';
}

void DFS(vector<string>&arr, vector<vector<bool>>&visited, int i, int j, int li, int lj, pair<int, int>e){
    int n = arr.size(), m = arr[0].size();
    if(i >= 0 && i < n && j >= 0 && j < m){
        if(i == e.first && j == e.second){
            if(li > i)
                printf("forth");
            else if(lj > j)
                printf("left");
            else
                printf("right");
            return;
        }
        if(!(li == i && lj == j)){
            if(!willNotBroke(arr[i][j]) || visited[i][j])
                return;
            visited[i][j] = true;
            if(li > i)
                printf("forth ");
            else if(lj > j)
                printf("left ");
            else
                printf("right ");
        }else
            visited[i][j] = true;
        DFS(arr, visited, i-1, j, i, j, e);
        DFS(arr, visited, i, j-1, i, j, e);
        DFS(arr, visited, i, j+1, i, j, e);
    }
}

int main(){
//    o:
    int t, n, m, f;
    pair<int, int>b, e;
    scanf("%i", &t);
    while(t--){
        scanf("%i%i", &n, &m);
        vector<string>arr(n);
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++){
            cin>>arr[i];
            f = arr[i].find("@");
            if(f != -1)
                b = make_pair(i, f);
            f = arr[i].find("#");
            if(f != -1)
                e = make_pair(i, f);
        }
        DFS(arr, visited, b.first, b.second, b.first, b.second, e);
        printf("\n");
    }
//    goto o;
    return 0;
}
