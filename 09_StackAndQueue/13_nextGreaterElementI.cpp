#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int, int>mpp;

        for(auto num: nums2){
            while(!st.empty() && st.top() < num){
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int>result;
        for(auto num: nums1){
            if(mpp.count(num)) result.push_back(mpp[num]);
            else result.push_back(-1);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int>arr1 = {1, 9}, arr2 = {1, 2, 6, 9, 8}, res;
    res = s.nextGreaterElement(arr1, arr2);
    for(auto it : res){
        cout<<it<<" ";
    }
    
    return 0;
}