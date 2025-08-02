#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node{

    public:
    Node* prev;
    int data;
    Node* next;

    Node(int d){
        this->prev = nullptr;
        this->data = d;
        this->next = nullptr;
    }

    Node(Node *prev, int d, Node* next){
        this->prev = prev;
        this->data = d;
        this->next = next;
    }
};

// Convert Array to DLL
Node *convertArrayToDll(vector<int>&arr){
    if(arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(int i = 1 ; i < arr.size() ; i++){
        Node* newNode = new Node(arr[i]);
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }

    return head;

}


// Display the DLL
void display(Node* head){
    if(head == nullptr){
        cout<<"Blank";
    }

    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


Node *dltAccurrencesOfKey(Node *head, int key){
    if(head==nullptr) return nullptr;

    Node *temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            if(temp == head){
                head = temp->next;
            }

            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}


int main() {

    vector<int>arr = {5, 10, 4, 10, 10, 8};
    Node* head = convertArrayToDll(arr);
    display(head);

    int key = 10;
    Node *result = dltAccurrencesOfKey(head, key);
    display(result);
    
    return 0;
}