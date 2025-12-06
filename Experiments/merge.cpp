#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>&intervals){
    int n = intervals.size();
    vector<vector<int>>ans;
    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for(int i = 0 ; i < n ; i++){
        vector<int> &v = ans.back();

        if(intervals[i][0] <= v[1]){
            v[1] = max(v[1],intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10},{7, 12}};
    arr = merge(arr);
    for(int i = 0 ; i<arr.size() ; i++){
        cout<< arr[i][0]<<", "<<arr[i][1];
        cout<<"\n";
    }
    return 0;
}