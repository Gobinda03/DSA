#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int ,int>p2){
if (p1.second<p2.second) return true;
if (p1.second>p2.second) return false;

//if they are same
if(p1.first>p2.first)  return true;
return false;

}
int main()
{
    int a,n,s;
    vector<int>s;
sort(a,a+n);
// sort(s.begin(),s.end());
sort(a+2,a+3);
pair<int ,int>a[]={{1,2},{3,4},{5,6}};

int maxi = max_element(a,a+n);
/*do
{
    cout<<s<<endl;
} while (next_permutation(s.begin(),s.end()));*/

return 0;
}