#include <bits/stdc++.h>
using namespace std;



vector<int> findSingle(vector<int> &nums){
    int n = nums.size();
    vector<int>res;

    // Bruteforce(TC => O(nlogm) + m ; SC = O(m))
    /*
    unordered_map<int, int> mpp;
    for(int i = 0 ; i < n ; i++){
        mpp[nums[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){
            res.push_back(it.first);
        }
    }
    return res;
    */
    

    // TC = O(2n) SC = O(1)
    long xorr = 0;
    for(int i = 0 ; i < n ; i++){
        xorr = xorr ^ nums[i];
    }
    int rightMost = (xorr ^ (xorr - 1)) & xorr;

    int b1 = 0, b2 = 0;

    for(int i = 0 ; i < n; i++){
        if(nums[i] & rightMost) b1 = b1 ^ nums[i];
        else b2 = b2 ^ nums[i];
    }
    return {b1, b2};

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

    cout<<"\nThe single elements of this array are: ";
    vector<int>ans = findSingle(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}