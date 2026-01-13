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


    // TC = O(n * 32) SC = O(1)
    /*
    int ans = 0;

    for(int bitIndex = 0 ; bitIndex < 31 ; bitIndex++){
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] & (1 << bitIndex)) cnt++;
        }
        if(cnt % 3 == 1) ans = ans | (1 << bitIndex);
    }
    return ans;
    */


    // TC = O(nlogn) + n/3  SC = O(1)
    /*
    sort(nums.begin(), nums.end());

    for(int i = 1 ; i < n ; i+=3){
        if(nums[i] != nums[i-1])return nums[i-1];
    }
    return nums[n-1];
    */

    // TC = O(n), SC = O(1)

    int ones = 0, twos = 0;
    for(int i = 0 ; i < n ; i++){
        ones = (ones ^ nums[i]) & (~twos);
        twos = (ones ^ nums[i]) & (~twos);
    }
    return ones;

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