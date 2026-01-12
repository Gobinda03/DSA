#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    int n = nums.size();
    int subset = 1<<n;
    vector<vector<int>> ans;

    for(int i = 0 ; i < subset ; i++){
        vector<int> list;

        for(int j = 0 ; j < n ; j++){
            if(i & (1 << j)){
                list.push_back(nums[j]);
            }
        }
        ans.push_back(list);
    }

    return ans;
}
int main()
{
    int n;
    cout<<"Enter the length of the array: ";
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
    cout<<"\n";

    vector<vector<int>> subsetsResult = subsets(arr);

    for(int i = 0 ; i < subsetsResult.size() ; i++){
        cout << "{ ";
        for(int j = 0 ; j < subsetsResult[i].size() ; j++){
            cout<<subsetsResult[i][j]<<" ";
        }
        cout << "}\n";
    }

    return 0;
}