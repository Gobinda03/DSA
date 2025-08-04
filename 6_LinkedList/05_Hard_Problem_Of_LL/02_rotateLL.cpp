#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=nullptr;
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
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


// Rotate the LL
Node *rotateLL(Node*head, int k){

    if(head == nullptr || k == 0) return head; //To handle NULL LL or K = 0

    // Find the lastNode and length of the List
    Node *tail = head;
    int len = 1;
    while(tail->next!=nullptr){
        tail = tail->next;
        len++;
    }
    k %= len;
    if(k == 0)return head;
    tail->next = head;

    // new lastNode
    int stepsToNewTail = len - k;
    Node *newLastNode = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newLastNode = newLastNode->next;
    }

    head = newLastNode->next;
    newLastNode->next = nullptr;
    return head;
}



int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40};

    Node* head1 = convertArrToLL(arr);
    int key = 3;

    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "After rotating the LL:\n";
    Node* result1 = rotateLL(head1, key);
    display(result1); cout << endl;

    return 0;
}