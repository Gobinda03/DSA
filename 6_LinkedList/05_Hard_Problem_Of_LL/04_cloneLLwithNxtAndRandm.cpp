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
    Node *result = cloneLL(head);
    display(result);

    return 0;
}