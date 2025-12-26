#include <bits/stdc++.h>
using namespace std;

int findEle(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n*m -1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        int row = mid/m, col = mid % m;

        if(mat[row][col] == target) return true;
        else if(mat[row][col] > target){
            high = mid-1;
        }
        else{
            low = mid + 1;
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
        cout<<"Element dose not exist";
    }
    return 0;
}