#include<bits/stdc++.h>
using namespace std;
// stack overflow as it doesnot meet any condition
/*void print()
{
    cout<<1;
    print();
    
}*/
int n=0;
void base()
{
//    int n=0;
   
   if (n==4)
   {
    return;
   }
    cout <<n<<endl;
   n++;
   base();
   

}
int main()
{
// print();
base();
return 0;
}