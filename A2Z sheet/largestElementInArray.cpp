#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cout<<"enter number";
    cin >> n;
    vector<int> arr(n);
    cout<<"the the array values";
    for(int i : arr){
        cin >> i;
    }
    int maxi = arr[0];
    for(int i = 1; i < arr.size();i++){
        if(maxi < arr[i]){
            maxi = arr[i];
        }
    }
    cout<< maxi;

}