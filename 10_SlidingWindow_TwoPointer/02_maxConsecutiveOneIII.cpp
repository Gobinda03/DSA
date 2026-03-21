#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // TC = O(N*N), SC = O(1)
    int longestOnesI(vector<int> &nums, int k){
        int n = nums.size();
        int maxlen = 0; 

        for(int i = 0 ; i < n ; i++){
            int zeros = 0;
            for(int j = i ; j < n ; j++){
                if(nums[j] == 0) zeros++;

                if(zeros <= k){
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }


    // TC = O(N + N), SC = O(1)
    int longestOnesII(vector<int> &nums, int k){
        int n = nums.size();
        int maxlen = 0; 
        int l = 0, r = 0;
        int zeros = 0;

        while(r < n){
            if(nums[r] == 0)zeros++;

            while(zeros > k){
                if(nums[l] == 0)zeros--;
                l++;
            }

            if(zeros <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
    
    
        // TC = O(N), SC = O(1)
    int longestOnesIII(vector<int> &nums, int k){
        int n = nums.size();
        int maxlen = 0; 
        int l = 0, r = 0;
        int zeros = 0;

        while(r < n){
            if(nums[r] == 0)zeros++;

            if(zeros > k){
                if(nums[l] == 0)zeros--;
                l++;
            }

            if(zeros <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnesI(nums, k) << endl;
    cout << sol.longestOnesII(nums, k) << endl;
    cout << sol.longestOnesIII(nums, k) << endl;
    
    return 0;
}