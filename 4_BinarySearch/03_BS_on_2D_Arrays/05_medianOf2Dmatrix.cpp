#include <bits/stdc++.h>
using namespace std;

int mini(vector<vector<int>> &mat, int n, int m){
    int minimum = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if(mat[i][0] < minimum){
            minimum = mat[i][0];
        }
    }
    return  minimum;
    
}
int maxi(vector<vector<int>> &mat, int n, int m){
    int maximum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(mat[i][m-1] > maximum){
            maximum = mat[i][m-1];
        }
    }
    return  maximum;
    
}



int findNum(vector<int> &arr, int target, int col) {
    int low = 0, high = col - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int Blackbox(vector<vector<int>> &mat, int n, int m, int target) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += findNum(mat[i], target, m);
    }
    return cnt;
}

int findMedian(vector<vector<int>> &mat, int row, int col) {
    int low = mini(mat, row, col);
    int high = maxi(mat, row, col);
    int req = (row * col + 1) / 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int smallerEqual = Blackbox(mat, row, col, mid);
        
        if (smallerEqual > req) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
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

    cout<<"The "<<findMedian(mat, n, m)<<" is the median of the given matrix";
    return 0;
} 