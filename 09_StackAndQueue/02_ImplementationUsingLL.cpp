#include <bits/stdc++.h>
using namespace std;

// Construction of Node
struct Node{
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};



// Stack implementation using Linked List
class stackImp{
private:
    Node* head;
    int size;

public:
    // Constructor;
    stackImp(){
        head = nullptr;
        size = 0;
    }
    // destroctor
    ~stackImp()
    {
        delete[] head;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        size +=1;
    }
    int pop(){
        if(size == 0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        int value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return value;
        size-=1;
    }
    int top(){
        if(head == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return head->data;
    }

    int length()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void show(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

// Queue implementation using Array
class queueImp{
private:
    Node* start;
    int size;
    Node* end;

public:
    // Constructor;
    queueImp(){
        start = end = nullptr;
        size = 0;
    }
    // destroctor
    ~queueImp()
    {
        delete[] start;
    }

    void push(int x){
        Node* temp = new Node(x);

        if(start == NULL){
            start = end = temp;
        }
        else{
            end->next = temp;
            end = temp;
        }
        size++;
    }
    int pop(){
        if(size == 0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        int value = start->data;
        Node *temp = start;
        start = start->next;
        delete temp;
        return value;
        size-=1;
    }
    int top(){
        if(start == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return start->data;
    }

    int length(){
        return size;
    }

    bool isEmpty(){
        return (size == 0);
    }

    void show(){
        Node* temp = start;
        while(temp->next->next != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};




int main()
{
    stackImp stack;
    queueImp qu;

    int choice, element, popped;

    // Stack
    do{
        cout << "\n1. Push  2. Pop  3. Top  4. Size  5. Empty?  6. Show  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                element;
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
                cout << "Top Element is: " << stack.top();
            break;

            case 4:
                cout << "Size: "<<stack.length();
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
    
    

    // Queue
    do{
        cout << "\n1. Push  2. Pop  3. Top  4. Size  5. Empty?  6. Show  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                element;
                cout << "Enter the element you want to push: ";
                cin >> element;
                qu.push(element);
                cout << element << " pushed\n";
            break;

            case 2:
                popped = qu.pop();
                if (popped != -1)
                {
                    cout << popped << " popped\n";
                }
            break;

            case 3:
                cout << "Top Element is: " << qu.top();
            break;

            case 4:
                cout << "Size: " << qu.length();
            break;

            case 5:
                qu.isEmpty() ? cout << "Empty." : cout << "Not empty." << endl;
            break;

            case 6:
                cout << "Queue: ";
                qu.show();
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