#include <bits/stdc++.h>
using namespace std;


// Stack implementation using Array
class stackImp{
private:
    int *stArray;
    int maxCapacity;
    int topInd;

public:
    // Constructor;
    stackImp(int size = 100)
    {
        maxCapacity = size;
        stArray = new int[maxCapacity];
        topInd = -1;
    }
    // destroctor
    ~stackImp()
    {
        delete[] stArray;
    }

    void push(int x)
    {
        if (topInd >= maxCapacity - 1)
        {
            cout << "Stack overFlow" << endl;
            return;
        }
        stArray[++topInd] = x; // increase by 1 then add value
    }
    int pop()
    {
        if (topInd == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return stArray[topInd--]; // return top element then decrease by 1
    }
    int top()
    {
        if (topInd == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stArray[topInd];
    }

    int size()
    {
        return topInd + 1;
    }

    bool isEmpty()
    {
        return topInd == -1;
    }

    void show()
    {
        for (int i = topInd; i >= 0; i--)
        {
            cout << stArray[i] << " ";
        }
        cout << endl;
    }
};


// Queue implementation using Array
class QueueImp{
private:
    int *qArray;
    int maxCapacity, currSize;
    int start, end;

public:
    // Constructor;
    QueueImp(int size = 100){
        maxCapacity = size;
        currSize = 0;
        qArray = new int[maxCapacity];
        start = end = -1;
    }
    // destroctor
    ~QueueImp(){
        delete[] qArray;
    }

    void push(int x){
        if (currSize == maxCapacity){
            cout << "Queue overFlow" << endl;
            return;
        }
        if(currSize == 0){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1) % maxCapacity;
        }

        qArray[end] = x;
        currSize+=1;
    }

    int pop(){
        if(currSize == 0){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        int popped = qArray[start];

        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1) % maxCapacity;
        }

        currSize --;
        return popped;
    }

    int top(){
        if (currSize == 0){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return qArray[start];
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return currSize == -1;
    }

    void show(){
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = start;
        for (int j = 0; j < currSize; j++) {
            cout << qArray[i] << " ";
            i = (i + 1) % maxCapacity;  // Traverse circularly
        }
        cout << endl;
    }
};

int main()
{
    stackImp stack;
    QueueImp qu;

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
                cout << "Size: " << qu.size();
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