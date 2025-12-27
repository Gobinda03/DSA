#include <bits/stdc++.h>
using namespace std;

bool findEle(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    int row = 0, col = m -1;

    while (row < n && col >= 0) {

        if(mat[row][col] == target) return true;
        else if(mat[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;             
}


int main()
{
    int n, m;
    cout<<"Number of Row: ";
    cin>> n;
    cout<<"Number of Column: ";
    cin>> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>mat[i][j];
        }
    }
    cout<< "Matrix: \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    int target;
    cout<<"Enter the target: ";
    cin>>target;

    if(findEle(mat, target)){
        cout<<"Element exists";
    }
    else{
        cout<<"Element does not exist";
    }
    return 0;
}