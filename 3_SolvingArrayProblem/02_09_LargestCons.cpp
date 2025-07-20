#include<bits/stdc++.h>
using namespace std;
bool lenearSearch(vector<int>&arr,int num){
    for (int i = 0; i < arr.size(); i++){
        if(num==arr[i]) return true;
    }
    return false;
}
int cons(vector<int>&arr){
    int largest = 1;
    for (int i = 0 ; i<arr.size() ; i++){
        int x = arr[i];
        int c = 1;

        while (lenearSearch(arr,x+1)==true){
            x = x+1;
            c++;
        }
        largest = max(largest,c);
    }
    return largest;

}
int conss(vector<int>&arr){
    int n = arr.size();
    if(n==0) return 0;

    int largest=1;
    unordered_set<int>st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for(auto it : st){
        if(st.find(it-1)==st.end()){
            int count = 1;
            int x  = it;

            while (st.find(x+1)!=st.end())
            {
                count++;
                x = x+1;
            }
                largest=max(largest,count);

        }


    }
    
    return largest;
}
int main()
{
    vector<int>arr={100,1,3,102,2,101,4};
    int r = cons(arr);
    int rr = conss(arr);

    cout<<r;
    cout<<rr;
    return 0;
}