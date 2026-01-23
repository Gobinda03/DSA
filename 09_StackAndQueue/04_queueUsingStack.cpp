#include <bits/stdc++.h>
using namespace std;


// Queue using Stack
// Approach I (TC = O(n))
class queueUsingStack{
stack<int>s1,s2;
public:

queueUsingStack(){

}
void push(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

int pop(){
    int n = s1.top();
    s1.pop();
    return n;
}

int topp(){
    if(s1.empty()) return -1;
    return s1.top();
}
bool isEmpty(){
    return s1.empty();
}

int size(){
    return s1.size();
}
void show(){
    stack<int> temp = s1;
    while(!temp.empty()){
        cout<< temp.top() <<" ";
        temp.pop();
    }
    cout << endl;
}

};
 
// Approach I (TC = O(n))
class queueUsingStackk{
stack<int>s1,s2;
public:

queueUsingStackk(){

}
void push(int x){
    s1.push(x);
}

int pop(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }


    if(s2.empty()) return -1;

    int x = s2.top();
    s2.pop();
    return x;
}

int topp(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty()) return -1;
    return s2.top();
}
bool isEmpty(){
    return s1.empty() && s2.empty();
}

int size(){
    return s1.size();
}
void show(){
    stack<int> temp = s1;
    while(!temp.empty()){
        cout<< temp.top() <<" ";
        temp.pop();
    }
    cout << endl;
}
    
};

int main(){
    queueUsingStack stack;
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