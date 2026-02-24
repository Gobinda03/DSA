#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        int n = nums.size();
        for(int i = 0 ; i <n ; i++){
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()]<nums[i])dq.pop_back();

            dq.push_back(i);

            if(i>=k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(arr, k);

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}