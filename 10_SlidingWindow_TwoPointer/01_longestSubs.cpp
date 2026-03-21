#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    // TC = O(N*N), SC = O(256)
    int longestNonRepeatingSubstringI(string &s){
        int n = s.length();
        int maxLen = 0;

        for(int i = 0 ; i < n ; i++){
            vector<int>hash(255, 0);

            for(int j = i ; j < n ; j++){
                if(hash[s[j]] == 1)break;

                hash[s[j]] ++;
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }


    // TC = O(N), SC = O(256)
    int longestNonRepeatingSubstringII(string &s){
        int n = s.length();
        int hash[256];

        for(int i = 0 ; i < 256 ; i++){
            hash[i] = -1;
        }
        int l = 0, r = 0, maxLen = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

int main(){
     string input = "cadbzabcd";
    
    //Create an instance of Solution class
    Solution sol;
    
    int lengthI = sol.longestNonRepeatingSubstringI(input);
    int lengthII = sol.longestNonRepeatingSubstringII(input);
    
    //Print the result
    cout << "Length of longest substring without repeating characters: " << lengthI << endl;
    cout << "Length of longest substring without repeating characters: " << lengthII << endl;
    
    return 0;
}