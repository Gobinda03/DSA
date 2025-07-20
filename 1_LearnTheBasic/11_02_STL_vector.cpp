#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    // Inserting the elements in vector

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "The elements are : ";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n The first element : " << v.front();
    cout << "\n The last element : " << v.back();
    cout << "\n The size of the element : " << v.size();
    vector<int>::iterator it=v.end();
    cout << "\n Deleting the element from the end : " << v[v.size() - 1];
    v.pop_back();
    cout << "\nprinting the vector after deleting the last element:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // inserting 5 at begining
    cout << "\nInterting 5 at 3rd position" << endl;
    v.insert(v.begin() + 2, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // Erasing the inserted element
    cout << "\nErasing the Inserted element" << endl;
    v.erase(v.begin() + 2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "now 3rd element is :" << v[2] << endl;
    if (v.empty())
    {
        cout << "\n vector is empty";
    }
    else
    {
        cout << "\n Vector is not empty";
    }
    v.clear();
    cout << "\nsize of the array after clrering all element is:" << v.size();
    if (v.empty())
    {
        cout << "\n now vector is empty";
    }
    else
    {
        cout << "\n now Vector is not empty";
    }
    v.clear();

    return 0;
}