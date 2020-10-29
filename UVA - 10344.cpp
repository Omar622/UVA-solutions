      /* Do it! */
     /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isSol;

bool allISUsed(vector<bool>& isUsed){
    for (int i = 0; i < 5; i++){
        if(isUsed[i] == false)
            return false;
    }
    return true;
}

void calc(int arr[], vector<bool> isUsed, ll last){
    if(isSol)
        return;
    if(last == 23 && !isSol && allISUsed(isUsed)){
        isSol = true;
        printf("Possible\n");
        return;
    }
    for (int i = 0; i < 5; i++){
        if(!isUsed[i]){
            isUsed[i] = true;
            calc(arr, isUsed, last + arr[i]);
            calc(arr, isUsed, last * arr[i]);
            calc(arr, isUsed, last - arr[i]);
            isUsed[i] = false;
        }
    }
}

int main() {
//    o:
    int arr[5];
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]){
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0){
            break;
        }
        vector<bool> isUsed(5, false);//by default 0
        isSol = false;
        for (int i = 0; i < 5; i++){
            isUsed[i] = true;
            calc(arr, isUsed, arr[i]);
            isUsed[i] = false;
        }
        if(!isSol)
            printf("Impossible\n");
    }
//    goto o;
    return 0;
}
