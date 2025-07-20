#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int n = arr.size();
    int count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0; // Reset sum for each new subarray start
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 3) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
