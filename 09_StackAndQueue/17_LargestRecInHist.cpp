#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int largestRectangleAreaI(vector<int> &heights) {
        int n = heights.size();
        int area = INT_MIN;
        for(int i = 0 ; i < n ; i++){

            int cnt = 0;
            for(int j = i ; j < n ; j++){
                if(heights[j]<heights[i]) break;
                else cnt++;
            }
            area = max((heights[i]*cnt), area);
        }

        return area;
    }

    int largestRectangleAreaII(vector<int> &heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ind = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, (nse-pse-1)*heights[ind]);
            }
            st.push(i);
        }
        

         while(!st.empty()){
                int ind = st.top();
                st.pop();

                int nse = n;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, (nse-pse-1)*heights[ind]);
            }

        return maxArea;
    }

    

};


int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    Solution obj;

    cout << "The largest area in the histogram is " << obj.largestRectangleAreaI(heights) << endl;
    cout << "The largest area in the histogram is " << obj.largestRectangleAreaII(heights) << endl;
    return 0;
}