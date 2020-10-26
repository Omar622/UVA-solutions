        /* Do it! */
       /*  OMAR  */
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int x, y;
    while(cin>>x>>y){
        cout<<setw(10)<<x<<setw(10)<<y<<"    "<<(__gcd(x, y) != 1 ? "Bad Choice\n\n" : "Good Choice\n\n");
    }
    return 0;
}
