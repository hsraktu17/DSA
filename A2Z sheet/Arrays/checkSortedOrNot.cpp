#include<bits/stdc++.h>

using namespace std;

bool checkSorted(vector<int> arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i-1] > arr[i]){
            return false;
        }
    }
    return true;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    bool check = checkSorted(arr);
    if(check == 1){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
}