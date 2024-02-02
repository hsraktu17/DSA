#include<bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    //Your code here
    if(s.empty()){
        return -1;
    }

    bool isNegative = false;
    if(s[0] == '-'){
        isNegative = true;
        s = s.substr(1);
    }

    int res = 0;
    for(char c : s){
        if(!isdigit(c)){
            return -1;
        }
        res = res * 10 + (c - '0');
    }
    if(isNegative == true){
        res *= -1;
    }
    return res;
}

int main(){
    string s = "123";
    int ans = myAtoi(s);
    cout << ans;
}