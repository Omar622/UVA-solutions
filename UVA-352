     /* Do it! */
    /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool flag;

void DFS(vector<string>&arr, vector<vector<bool>>&visited, int i, int j){
    int n = arr.size();
    if(i >= 0 && i < n && j >= 0 && j < n){
        if(arr[i][j] == '0' || visited[i][j])
            return;
        else
            flag = true;
        visited[i][j] = true;
        DFS(arr, visited, i-1, j-1);
        DFS(arr, visited, i-1, j);
        DFS(arr, visited, i-1, j+1);
        DFS(arr, visited, i, j-1);
        DFS(arr, visited, i, j+1);
        DFS(arr, visited, i+1, j-1);
        DFS(arr, visited, i+1, j);
        DFS(arr, visited, i+1, j+1);
    }
}


int main(){
//    o:
    int n, c, indx = 0;
    while(cin>>n){
        c = 0;
        vector<string>arr(n);
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(!visited[i][j]){
                    flag = false;
                    DFS(arr, visited, i, j);
                    if(flag)
                        c++;
                }
            }

        }
        indx++;
        printf("Image number %i contains %i war eagles.\n", indx, c);
    }
//    goto o;
    return 0;
}
