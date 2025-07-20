#include <bits/stdc++.h>
using namespace std;

// bruteforce
vector<vector<int>> RotateMatrix(vector<vector<int>>&matrix , int n , int m){
    vector<vector<int>>result(m,vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            result[j][n-1-i]=matrix[i][j];
        }
    }
    return result;
}


int main() {
    vector<vector<int>>matrix = {{ 1, 2, 3, 4},{ 5, 6, 7, 8},{ 9,10,11,12},{13,14,15,16}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = RotateMatrix(matrix,n,m);
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    return 0;
}