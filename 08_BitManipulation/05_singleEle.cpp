#include <bits/stdc++.h>
using namespace std;

int findSingle(vector<int> &nums){
    int n = nums.size();

    // Bruteforce(TC => O(nlogm) + m ; SC = O(m))
    /*
    unordered_map<int, int> mpp;
    for(int i = 0 ; i < n ; i++){
        mpp[nums[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1) return it.first;
    }
    return 0;
    */

    int xorr = 0;

    for(auto it : nums){
        xorr = xorr ^ it;
    }
    return xorr;

}
int main()
{
    int n;
    cout<<"Enter the size of the number list: ";
    cin>>n;
    vector<int>arr;
    int num;
    for(int i = 0 ; i < n ; i++){
        cin>>num;
        arr.push_back(num);
    }

    for(auto it : arr){
        cout<<it<<" ";
    }

    cout<<"\nThe single element of this array is: "<<findSingle(arr);
    return 0;
}