#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
         int n = nums.size();        
        vector<int>nge(n);
        stack<int>st;

        for(int i = 2*n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty()? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};

int main()
{
    Solution s;
    vector<int>arr1 = {1, 2, 6, 9, 8}, res;
    res = s.nextGreaterElement(arr1);
    for(auto it : res){
        cout<<it<<" ";
    }
    
    return 0;
}