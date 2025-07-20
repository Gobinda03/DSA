#include <bits/stdc++.h>
using namespace std;
//Brute force Approach
int missingNumber1(vector<int>&a,int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for(int j=0 ; j<n; j++)
        {
            if (a[j]==i)
            {
                flag =1;
                break;
            }
            
        }
        if (flag==0)
        {
            return i;
        }
    }
    return -1;
    
}
//Better Approach
int missingNumber2(vector<int>&a, int N) {

    int hash[N+1] = {0};

    for (int i = 0; i < N ; i++)
        hash[a[i]]++;

    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int N = a.size();
    int ans1 = missingNumber1(a,N);
    int ans2 = missingNumber2(a,N);
    cout << "The missing number is: " << ans1 << endl;
    cout << "The missing number is: " << ans2 << endl;
    return 0;
}

