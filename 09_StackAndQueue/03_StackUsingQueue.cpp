#include <bits/stdc++.h>
using namespace std;


// Stack Using Queue
class StackUsingQueue{
queue <int> q;
public:
void push(int x){
    int n = q.size();
    q.push(x);
    for(int i = 0 ; i < n ; i++){
        q.push(q.front());
        q.pop();
    }
}

int pop(){
    if(q.empty()) return -1;
    int n = q.front();
    q.pop();
    return n;
}

int topp(){
    return q.front();
}
bool isEmpty(){
    return q.empty();
}

int size(){
    return q.size();
}
void show(){
    queue<int> temp = q;
    while(!temp.empty()){
        cout<< temp.front() <<" ";
        temp.pop();
    }
    cout << endl;
}
    
};

int main(){
    StackUsingQueue stack;
    int choice,popped;
    do{
        cout << "\n1. Push  2. Pop  3. Top  4. Size  5. Empty?  6. Show  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                int element;
                cout << "Enter the element you want to push: ";
                cin >> element;
                stack.push(element);
                cout << element << " pushed\n";
            break;

            case 2:
                popped = stack.pop();
                if (popped != -1)
                {
                    cout << popped << " popped\n";
                }
            break;

            case 3:
                cout << "Top Element is: " << stack.topp();
            break;

            case 4:
                cout << "Size: " << stack.size();
            break;

            case 5:
                stack.isEmpty() ? cout << "Empty." : cout << "Not empty." << endl;
            break;

            case 6:
                cout << "Stack: ";
                stack.show();
            break;

            case 0:
                cout << "Exit\n";
            break;

            default:
                cout << "Wrong input.";
            break;
        }

    } while (choice != 0);
    
    
    return 0;
}