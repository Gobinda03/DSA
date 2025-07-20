#include <bits/stdc++.h> 
using namespace std;



vector<int> addOneToNumber(vector<int> arr)
{
    // Write your code here
     vector<int>v;
    stack<int>st;
    int num= 0 , cnt=0;
    int n = arr.size();

    for(int i = 0 ; i<n ; i++){
        num = num*10 + arr[i];
    }
    int totalnum=num+1;
    arr.clear();
    while(totalnum>0){
        int newnum= totalnum%10;
        totalnum = totalnum/10;
        arr.insert(arr.begin(),newnum);
    }
    return arr;
}



int main() {
    int T;
    cin >> T; // Number of test cases
    
    while (T--) {
        int N;
        cin >> N; // Size of the array
        
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        
        vector<int> result = addOneToNumber(arr);
        
        // Print the result
        for (int digit : result) {
            cout << digit << " ";
        }
        cout << endl;
    }
    
    return 0;
}