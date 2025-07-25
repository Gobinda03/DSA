#include <bits/stdc++.h>
using namespace std;

vector<int>spiralMatrix(vector<vector<int>>&matrix, int n , int m){
    int top = 0 , bottom = n-1;
    int left = 0 , right = n-1;
    vector<int>res;
    while(left<=right && top <= bottom){
        for(int i = left ; i <= right ; i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ; i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i = right ; i>=left ;i--){
                res.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left <= right){
        
            for(int i = bottom ; i >= top ; i--){
                res.push_back(matrix[i][left]);
            }
        }
        left++;
    }  
    return res;  
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>ans = spiralMatrix(matrix,n,m);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}