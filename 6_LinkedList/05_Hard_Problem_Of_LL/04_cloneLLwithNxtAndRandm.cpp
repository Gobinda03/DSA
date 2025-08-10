#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;
    Node *random;

    Node(): data(0), next(nullptr), random(nullptr){};
    
    Node(int d){
        this->data=d;
        this->next=nullptr;
        this->random = nullptr;
    }
};


// Array to LinkedList
Node*convertArrToLL(vector<int>&arr){
    if(arr.size()==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node*temp = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node*newNode = new Node(arr[i]);
        temp->next=newNode;
        temp = newNode;
    }
    return head;
}


// Display LinkedList
void display(Node*head){
    if(head==nullptr){
        cout<<"Blank";
    }
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }

}

// Copy list with the random pointer
// TC =O(2N)    SC = O(2N)
Node *cloneLL(Node *head){
    if(head == nullptr) return head;
    Node *temp = head;
    unordered_map<Node*, Node*> mpp;

    while(temp!=nullptr){
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}


// Copy list with the random pointer 2nd Method
// TC =O(3N)    SC = O(N)
Node *cloneLL2(Node *head){
    if(head == nullptr) return head;
    Node *temp = head;
    
    while(temp!=nullptr){
        Node *copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    temp = head;
    while(temp!=nullptr){
        Node *copyNode = temp->next;
        if(temp->random){
            copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }

    temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(temp!=nullptr){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp= temp->next;
    }

    return dummyNode->next;
}


int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;


    cout << "Original:\n";
    display(head); cout << endl;

    cout << "Copy list with  random pointer:\n";
    Node *result = cloneLL2(head);
    display(result);

    return 0;
}