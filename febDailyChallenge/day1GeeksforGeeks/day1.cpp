#include<bits/stdc++.h>

using namespace std;

bool checkPangram (string s) {
    // your code here
    unordered_set<char> set;
    for(char c : s){
        char lowerCase = tolower(c);
        if(isalpha(lowerCase)){
            set.insert(lowerCase);
        }
    }
    return set.size() == 26;
}

int main(){
    string s = "Bawds jog, flick quartz, vex nymph";
    bool check = checkPangram(s);
    cout<<check;
}