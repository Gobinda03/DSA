#include <bits/stdc++.h>
using namespace std;

int findOne(vector<int> &arr, int col){
    int low = 0, high = col - 1, mid;
    int firstOne = col;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == 1) {           
            firstOne = mid;           
            high = mid - 1;            
        } else {                      
            low = mid + 1;              
        }
    }
    return col - firstOne;             
}

int rowWithMaxOne(vector<vector<int>> &mat, int row, int col){
    int max_one = -1;
    int row_num = -1;
    int One;

    for(int i = 0 ; i< row ; i++){
        One = findOne(mat[i],col);

        if(One > max_one){
            max_one = One;
            row_num = i;
        }
    }
    return row_num;
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

    cout<<"The "<<rowWithMaxOne(mat, n, m)<<"th row has maximum number of ones";
    return 0;
}