#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();        
        vector<int>nge(n, -1);
        stack<int>st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nge;
    }
};

int main()
{
    Solution s;
    vector<int>arr1 = {4, 8, 5, 2, 25}, res;
    res = s.nextGreaterElement(arr1);
    for(auto it : res){
        cout<<it<<" ";
    }
    
    return 0;
}