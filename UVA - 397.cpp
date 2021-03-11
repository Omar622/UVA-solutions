       /* Do it! */
      /*  OMAR  */
#include<bits/stdc++.h>
using namespace std;
#define siz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define PI acos(-1.0)
typedef long long ll;


int getNum(string str){
    string temp = "";
    for (int i = 0; i < siz(str); ++i){
        if(str[i] != ' ')
            temp += str[i];
    }
    if(temp == "") return 0;
    return stoi(temp);
}

void sol(string& line, int idx, char op){
    int l = 0, r;

    int i = idx+1;// =
    while(!isdigit(line[i])) ++i;
    while(isdigit(line[i])) ++i;
    r = i-1;

    i = idx-1;
    while(i >= 0 && !isdigit(line[i])) --i;
    while(i >= 0 && isdigit(line[i])) --i;
    if(i == -1)
        l = 0;
    else if(line[i] == '-')
        l = i;
    else
        l = i+1;


    int opl, opr, res;
    opl = getNum(line.substr(l, idx-1));
    opr = getNum(line.substr(idx+1, r));
  
    switch(op){
    case '+':
        res = opl + opr;
        break;
    case '-':
        res = opl - opr;
        break;
    case '*':
        res = opl * opr;
        break;
    case '/':
        res = opl / opr;
        break;
    }
    line.replace(l, r-l+1, to_string(res));
}

void format(string& line){
    for (int i = 0; ; ++i){//add spaces
        if(!isdigit(line[i]) && line[i] != ' '){
            line.insert(i+1, " ");
            line.insert(i, " ");
            ++i;
        }
        if(line[i] == '=') break;
    }

    int spc = line.find("  ");//shrink spaces
    while(spc != -1){
        line.replace(spc, 2, " ");
        spc = line.find("  ");
    }

    // modify +, -
    for(int i = 0; line[i] != '='; ++i){
        if(!isdigit(line[i]) && line[i] != ' '){
            bool isSign = i-2 == -1 || !isdigit(line[i-2]);
            if(isSign){
                if(line[i] == '-'){
                    line.erase(i+1, 1);
                }else if(line[i] == '+'){
                     line.erase(i, 2);
                }
            }
        }
    }

    if(line[0] == ' ')
        line.erase(0, 1);
}


int main(){
    FIO
    o:

    string line;
    int add, sub, mul, div;
    while(getline(cin, line)){
        format(line);
        cout << line << "\n";

        mul = line.find(" * ") + 1;
        div = line.find(" / ") + 1;
        while(mul || div){
            if(!mul){
                sol(line, div, '/');
            }else if(!div){
                sol(line, mul, '*');
            }else if(mul < div){
                sol(line, mul, '*');
            }else{
                sol(line, div, '/');
            }
            cout << line << "\n";
            mul = line.find(" * ") + 1;
            div = line.find(" / ") + 1;
        }

        add = line.find(" + ") + 1;
        sub = line.find(" - ") + 1;
        while(add || sub){
            if(!add){
                sol(line, sub, '-');
            }else if(!sub){
                sol(line, add, '+');
            }else if(add < sub && add != -1){
                sol(line, add, '+');
            }else{
                sol(line, sub, '-');
            }
            cout << line << "\n";
            add = line.find(" + ") + 1;
            sub = line.find(" - ") + 1;
        }

        cout << "\n";
    }

//    goto o;
    return 0;
}
