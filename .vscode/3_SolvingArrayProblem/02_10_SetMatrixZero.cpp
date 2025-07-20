#include <bits/stdc++.h>
using namespace std;
// void markRow(int arr[3][3],int i){
//     for(int j = 0 ; j < 3 ; j++){
//         if(arr[i][j]!=0){
//             arr[i][j]=-1;
//         }
//     }
// }
// void markCol(int arr[3][3],int j){
//     for(int i = 0 ; i < 3 ; i++){
//         if(arr[i][j]!=0){
//             arr[i][j]=-1;
//         }
//     }
// }


// Brute Force Solution
// void markRow(vector<vector<int>>&matrix , int n , int m , int i){
//     for(int j = 0 ; j < n ; j++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }
//  }
// void markCol(vector<vector<int>>&matrix , int n , int m , int j){
//     for(int i = 0 ; i < m ; i++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }
//  }
// vector<vector<int>> zeromatrix(vector<vector<int>>&matrix , int n , int m){
//         for (int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if (matrix[i][j]==0){
//                 markRow(matrix,n,m,i);
//                 markCol(matrix,m,n,j);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if (matrix[i][j]==-1){
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     return matrix;
// }

vector<vector<int>> zeromatrix(vector<vector<int>>&matrix,int n,int m){
    int col[m] = {0};
    int row[n] = {0};

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}
int main() {
    // int arr[3][3];
    // for (int i = 0; i < 3; i++){
    //     for(int j = 0 ; j < 3 ; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for (int i = 0; i < 3; i++){
    //     for(int j = 0 ; j < 3 ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for (int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         if (arr[i][j]==0){
    //             markRow(arr,i);
    //             markCol(arr,j);
    //         }
    //     }
    // }
    // for(int i = 0 ; i < 3 ; i++){
    //     for(int j = 0 ; j < 3 ; j++){
    //         if(arr[i][j]==-1){
    //             arr[i][j]=0;
    //         }
    //     }
    // }
    // for (int i = 0; i < 3; i++){
    //     for(int j = 0 ; j < 3 ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }



    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = zeromatrix(matrix,n,m);
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    return 0;
}