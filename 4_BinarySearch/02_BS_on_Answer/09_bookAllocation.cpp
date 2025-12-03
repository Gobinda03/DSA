#include <bits/stdc++.h>
using namespace std;


int countStd(vector<int>&arr, int noOfPage){
    int countStd = 1, pages = 0;

    for(int i = 0 ; i < arr.size() ; i++){
        if(pages + arr[i] <= noOfPage){
            pages += arr[i];
        }
        else{
            countStd++;
            pages = arr[i];
        }
    }
    return countStd;
}
int bookAllocated(vector<int>&arr, int student){
    int low = *max_element(arr.begin(), arr.end()), mid, high = accumulate(arr.begin(), arr.end(),0);

    while(low <= high){
        mid = low + (high-low)/2;
        int countStudents = countStd(arr, mid);
        if(countStudents > student){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return low;
}

int main()
{
    cout<<"Enter the no of books: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the number of students: ";
    int students;
    cin>>students;

    cout<<"The max pages assigned to a students which is minimum is: "<<bookAllocated(arr,students);
    return 0;
}




// for linear search operation TC is Big O(NlogN) + Big O((arr(Max) - arr(min)) * N)
// For BS TC is Big O(NlogN) + Big O((log(arr(Max) - arr(min))) * N)