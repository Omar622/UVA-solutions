       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

vector<int> LIS(vector<int>&arr, int n){//
    vector<int>res(n);
    int l = 1, tail[n] = {0};
    int* ptr;

    tail[0] = arr[0];
    for (int i = 1; i < n; i++){
        ptr = lower_bound(tail, tail+l, arr[i]);

        if(ptr == tail+l){
            tail[l++] = arr[i];
        }else{
            *ptr = arr[i];
        }

        res[i] = l;
    }

    return res;
}

int main(){
//    o:
    init();
    int n, M;
    while(cin>>n){
        M = 1;
        vector<int>v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        vector<int>I = LIS(v, n);
        reverse(v.begin(), v.end());
        vector<int>D = LIS(v, n);

        for (int i = 0; i < n; i++){
            if(I[i] == D[n-i-1])
                M = max(M, I[i]+D[n-i-1]-1);
        }
        cout << M << "\n";
    }

//    goto o;
    return 0;
}
