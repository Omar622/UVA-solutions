        /* Do it! */
       /*  OMAR  */
#include <bits/stdc++.h>
using namespace std;

string operator*(string x, string y){
    if(!x.size() || !y.size())
        return "0";

    
    int r = 0, res0, i_n1 = 0, i_n2 = 0;
    vector<int> result(x.size() + y.size(), 0);

    for (int i = y.size()-1; i >= 0; i--){
        int carry = 0;
        int n1 = y[i] - '0';
        i_n2 = 0;

        for (int j = x.size()-1; j >= 0; j--){
            int n2 = x[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && !result[i])
        i--;

    if (i == -1)
        return "0";
        
    string res;
    while (i >= 0)
        res += to_string(result[i--]);

    return res;

}

int main(){
    string a, b, res;
    while(cin>>a>>b){
        res = a*b;
        cout<<res<<endl;
    }
    return 0;
}
