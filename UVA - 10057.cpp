       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    o:
    int n, l, r, c;
    while(cin>>n){
        c = 0;
        int arr[n];
        for (int i = 0; i < n; i++){
            scanf("%i", arr+i);
        }
        sort(arr, arr+n);
        if(n % 2 == 0){
            l = arr[n/2 - 1],//nearest element to all elements
            r = arr[n/2];//nearest element to all elements
        }else{
            l = r = arr[n/2];//nearest element to all elements
        }

        for (int i = 0; i < n; i++){
            if(l <= arr[i] && arr[i] <= r){
                c++;
            }
        }
        printf("%i %i %i\n", l, c, r-l+1);
    }
//    goto o;
    return 0;
}
