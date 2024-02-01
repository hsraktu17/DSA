#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> divideArray(vector<int>& num, int k){
    vector<vector<int>> res;
    vector<int> vec;
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size(); i++){
        if(vec.empty()){
            vec.push_back(num[i]);
        }else if(vec.size() == 3){
            res.push_back(vec);
            vec.clear();
            i--;
        }else{
            if(num[i]-vec[0] <= k){
                vec.push_back(num[i]);
            }else{
                return{};
            }
        }
        
    }
    
    return res;
}

int main(){
    vector<int>vec = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> res =  divideArray(vec, k);
    for(int i = 0;i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout<<res[i][j] << " ";
        }
        cout<<endl;
    }
}