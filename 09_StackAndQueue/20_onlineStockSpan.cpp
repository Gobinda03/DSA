#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int, int>>st;
    int ind = -1;
public:
    StockSpanner() {
        ind = -1;
    }

    int next(int price) {
        ind = ind + 1;
       
        while(!st.empty() && st.top().first <= price) st.pop();

        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        
        return ans;

    }
};

int main(){
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};

    StockSpanner sol; 

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        ans.push_back(sol.next(arr[i]));
    }
    
    cout << "The span of stock prices is: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}