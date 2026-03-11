#include<bits/stdc++.h>
using namespace std;

class findCelebrity{
    public:
    int celebrity(vector<vector<int>> &mat){
        int n = mat.size();
        int top = 0 , down = n-1;

        while(top < down){
            if(mat[top][down] == 1) top ++;
            else if(mat[down][top] == 1) down--;
            else{
                top ++;
                down--;
            }
        }

        if(top > down) return -1;
        for(int i = 0 ; i < n ; i++){
            if(i == top) continue;

            if(mat[top][i] == 1 || mat[i][top] == 0) return -1;
        }
        return top;
    }
};

int main(){

    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };
    
    findCelebrity sol; 
    
    int ans = sol.celebrity(M);
    
    cout << "The index of celebrity is: " << ans<<endl;
    cout<< "TC: O(N) and SC: O(1)";
    return 0;
}