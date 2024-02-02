#include<bits/stdc++.h>

using namespace std;

vector<int> sequentialDigits(int low, int high) {
    string s = "123456789";
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        string x = "";
        for(int j = i; j < s.size(); j++){
            x += s[j];
            int n = stoi(x);
            if(n >= low && n <= high){
                ans.push_back(n);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int low = 100;
    int high = 300;
    vector<int> ans = sequentialDigits(low, high);
    for(int i : ans){
        cout<<i<<" ";
    }
}