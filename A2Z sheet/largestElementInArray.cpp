#include<bits/stdc++.h>

using namespace std;

int maxii(vector<int> a){
    int maxi = a[0];
    for(int i = 0; i < a.size(); i++){
        if(maxi < a[i]){
            maxi = a[i];
        }
    }
    return maxi;
}

int main(){
    vector<int> num = {12,3,53,2,5,1};
    int ans = maxii(num);
    cout<<ans;
}