#include<bits/stdc++.h>

using namespace std;

vector<int> removeDuplicate(vector<int> arr){
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 0 ; i < arr.size()-1; i++){
        if(arr[i] != arr[i+1]){
            ans.push_back(arr[i+1]);
        }
    }
    return ans;

}


int main(){
    vector<int> arr = {0,1,1,1,2,2,2,2,3,3,3,4};
    vector<int> ans = removeDuplicate(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
}