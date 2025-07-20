#include <bits/stdc++.h>
using namespace std;

int factors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}
//method 2
int factor2(int n)
{
    vector<int>ls;
    for (int i = 1; i <= sqrt(n) ; i++)
    {
        if(n%i==0)
        {
        //    cout<< i <<" "; 
           ls.push_back(i);
            if ((n/i)!=i)
            {
                // cout<< n/i <<" ";
                ls.emplace_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end());
    for (auto it : ls)
    {
        cout<< it << " ";
    }

    cout <<endl;
    // for sorting method 2
    set<int>s;
    for (int i = 1; i <= sqrt(n) ; i++)
    {
        if(n%i==0)
        {
        //    cout<< i <<" "; 
           s.insert(i);
            
            s.insert((n/i));
        }
    }
    // sort(ls.begin(),ls.end());
    for (auto it : s)
    {
        cout<< it << " ";
    }
    
    
}
int main()
{
    int n;
    cout << "Enter the number :";
    cin >> n;
    cout << "\nAll the Divisions of " << n << " are :";
    factors(n);
    cout << "\n method 2 All the Divisions of " << n << " are :";
    factor2(n);
    return 0;
}